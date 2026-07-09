#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000
#define FRAMES 20

typedef struct Entity {
    float x, y, vx, vy;
    void (*update)(struct Entity *);
} Entity;

static void entity_update(Entity *e) {
    e->x += e->vx;
    e->y += e->vy;
}

static double now_sec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

static void shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }
}

double run_oop(void) {
    Entity **entities = malloc(sizeof(Entity*) * N);
    for (int i = 0; i < N; i++) {
        entities[i] = malloc(sizeof(Entity));
        entities[i]->x = (float)i;
        entities[i]->y = (float)i;
        entities[i]->vx = 0.001f;
        entities[i]->vy = 0.001f;
        entities[i]->update = entity_update;
    }

    int *order = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) order[i] = i;
    shuffle(order, N);

    double t0 = now_sec();
    for (int f = 0; f < FRAMES; f++) {
        for (int i = 0; i < N; i++) {
            Entity *e = entities[order[i]];
            e->update(e);
        }
    }
    double t1 = now_sec();

    double checksum = 0;
    for (int i = 0; i < N; i++) checksum += entities[i]->x;
    printf("  [OOP checksum: %f]\n", checksum);

    for (int i = 0; i < N; i++) free(entities[i]);
    free(entities);
    free(order);
    return t1 - t0;
}

double run_dod(void) {
    float *x  = malloc(sizeof(float) * N);
    float *y  = malloc(sizeof(float) * N);
    float *vx = malloc(sizeof(float) * N);
    float *vy = malloc(sizeof(float) * N);

    for (int i = 0; i < N; i++) {
        x[i] = (float)i; y[i] = (float)i;
        vx[i] = 0.001f; vy[i] = 0.001f;
    }

    double t0 = now_sec();
    for (int f = 0; f < FRAMES; f++) {
        for (int i = 0; i < N; i++) {
            x[i] += vx[i];
            y[i] += vy[i];
        }
    }
    double t1 = now_sec();

    double checksum = 0;
    for (int i = 0; i < N; i++) checksum += x[i];
    printf("  [DOD checksum: %f]\n", checksum);

    free(x); free(y); free(vx); free(vy);
    return t1 - t0;
}

static void update_fn(float *x, float *y, float *vx, float *vy) {
    *x += *vx;
    *y += *vy;
}

double run_dod_indirect(void) {
    float *x  = malloc(sizeof(float) * N);
    float *y  = malloc(sizeof(float) * N);
    float *vx = malloc(sizeof(float) * N);
    float *vy = malloc(sizeof(float) * N);
    void (**fns)(float*, float*, float*, float*) = malloc(sizeof(void*) * N);

    for (int i = 0; i < N; i++) {
        x[i] = (float)i; y[i] = (float)i;
        vx[i] = 0.001f; vy[i] = 0.001f;
        fns[i] = update_fn;
    }

    double t0 = now_sec();
    for (int f = 0; f < FRAMES; f++) {
        for (int i = 0; i < N; i++) {
            fns[i](&x[i], &y[i], &vx[i], &vy[i]);
        }
    }
    double t1 = now_sec();

    double checksum = 0;
    for (int i = 0; i < N; i++) checksum += x[i];
    printf("  [DOD+indirect checksum: %f]\n", checksum);

    free(x); free(y); free(vx); free(vy); free(fns);
    return t1 - t0;
}

int main(void) {
    srand(42);

    printf("N = %d entities, %d frames\n\n", N, FRAMES);

    printf("Running OOP (AoS, heap-scattered, shuffled access, indirect call)...\n");
    double t_oop = run_oop();
    printf("  time: %.3f s\n\n", t_oop);

    printf("Running DoD (SoA, contiguous, direct ops, sequential access)...\n");
    double t_dod = run_dod();
    printf("  time: %.3f s\n\n", t_dod);

    printf("Running DoD+indirect (SoA, contiguous, but called via function pointer)...\n");
    double t_dod_ind = run_dod_indirect();
    printf("  time: %.3f s\n\n", t_dod_ind);

    printf("Speedup DoD vs OOP:          %.2fx\n", t_oop / t_dod);
    printf("Speedup DoD vs DoD+indirect: %.2fx\n", t_dod_ind / t_dod);
    printf("Speedup DoD+indirect vs OOP: %.2fx\n", t_oop / t_dod_ind);

    return 0;
}
