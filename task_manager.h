// task_manager.h
#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>

using namespace std;

struct Task
{
    string title;
    string description;
};

class TaskManager{
    public:
        // Accepts reference to an object and const ensures not to modify any of the passed references
        void addTask(const string& title, const string& description);
        // Only lists down the tasks and const ensures no modification only read
        void listTasks() const;
        bool updateTask(const string& title, const string& newTitle, const string& newDescription);
        bool deleteTask(const string& title);
    private:
        // Dynamic array automatically allocated or deallocated, contiguous memory locations, providing efficient memory access and cache locality
        vector<Task> tasks;
};

#endif