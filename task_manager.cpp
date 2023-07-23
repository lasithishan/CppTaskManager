// task_manager.cpp
#include "task_manager.h"
#include <iostream>
#include <algorithm>

void TaskManager::addTask(const string& title, const string& description) {
    Task task = {title, description};
    tasks.push_back(task);
    cout << "Task added successfully." << endl;
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "List of tasks:" << endl;
    for (const Task& task : tasks) {
        cout << "Title: " << task.title << endl;
        cout << "Description: " << task.description << endl;
        cout << "---------------" << endl;
    }
}

bool TaskManager::updateTask(const string& title, const string& newTitle, const string& newDescription) {
    auto taskIt = find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.title == title;
    });

    if (taskIt != tasks.end()) {
        taskIt->title = newTitle;
        taskIt->description = newDescription;
        cout << "Task updated successfully." << endl;
        return true;
    }

    cout << "Task not found." << endl;
    return false;
}

bool TaskManager::deleteTask(const string& title) {
    auto taskIt = find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.title == title;
    });

    if (taskIt != tasks.end()) {
        tasks.erase(taskIt);
        cout << "Task deleted successfully." << endl;
        return true;
    }

    cout << "Task not found." << endl;
    return false;
}
