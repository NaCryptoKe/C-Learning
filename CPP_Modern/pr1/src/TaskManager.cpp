#include "TaskManager.hpp"

void TaskManager::addTask(const Task&& task) {
    tasks.push_back(task);
}
