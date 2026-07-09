#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <cstddef>

class Task {
public:
    enum class State { COMPLETED, IN_PROGRESS, DEFERRED, CANCELED, ADDED };

    Task(const std::size_t id, const std::string &title);

    void complete();
    void cancel();
    void start();
    void defer();

    std::size_t getId() const { return id; }
    const std::string& getTitle() const { return title; }
    State getState() const { return state; }

private:
    std::size_t     id;    // Used unsigned int so that int could never get a UB (Undefined Behaviour)
    std::string     title;
    State           state;
};

#endif  // TASK_HPP
