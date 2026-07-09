#include <stdio.h>
#include <stdbool.h>

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);
double mod(double a, double b);

bool valid_denominator(double denominator);     // Invarian 1: checking to not divide by 0

int main(void) {
    double a = 0, b = 0;
    char op;

    printf("Enter num 1: ");
    scanf("%lf", &a);
    printf("Enter op: ");
    scanf("%c", &op);
    printf("Enter num 2: ");
    scanf("%lf", &b);

    switch (op) {
        case '+':
            printf("%ld %c %ld = %ld\n", a, op, b, add(a, b));
            break;
        case '-':
            printf("%ld %c %ld = %ld\n", a, op, b, sub(a, b));
            break;
        case '*':
            printf("%ld %c %ld = %ld\n", a, op, b, mul(a, b));
            break;
        case '/':
            if (!valid_denominator(b)) {
                printf("You can't divide by 0\n");
                break;
            }
            printf("%ld %c %ld = %ld\n", a, op, b, div(a, b));
            break;
        case '%':
            printf("%ld %c %ld = %ld\n", a, op, b, mod(a, b));
            break;
        default:
            printf("Enter a valid operation\n");
            break;
    }
}

double add(double a, double b) {
    return a + b;
}
double sub(double a, double b) {
    return a - b;
}
double mul(double a, double b) {
    return a * b;
}
double div (double a, double b) {
    return a / b;
}
double mod(double a, double b) {
    return (int)a % (int)b;
}
bool valid_denominator(double denominator) {
    if (denominator == 0) return false;
    return true;
}
