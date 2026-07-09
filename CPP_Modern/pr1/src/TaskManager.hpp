#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <vector>
#include "Task.hpp"

class TaskManager {
public:
    void addTask(const Task&& task);

private:
    std::vector<Task> tasks = {};
};
#endif // TASK_MANAGER_HPP
