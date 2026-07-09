#include "Task.hpp"

Task::Task(const std::size_t id, const std::string &title) : id(id), title(title), state(State::ADDED) {}

void Task::complete() {
    state = State::COMPLETED;
}

void Task::cancel() {
    state = State::CANCELED;
}

void Task::start() {
    state = State::IN_PROGRESS;
}

void Task::defer() {
    state = State::DEFERRED;
}
