// main.cpp
#include <iostream>
#include <string>
#include "task_manager.h"

int main() {
    TaskManager taskManager;
    int choice;

    do {
        cout << "Task Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. List Tasks" << endl;
        cout << "3. Update Task" << endl;
        cout << "4. Delete Task" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character from previous input

        switch (choice) {
            case 1: {
                string title, description;
                cout << "Enter task title: ";
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                taskManager.addTask(title, description);
                break;
            }
            case 2:
                taskManager.listTasks();
                break;
            case 3: {
                string title, newTitle, newDescription;
                cout << "Enter task title to update: ";
                getline(cin, title);
                cout << "Enter new task title: ";
                getline(cin, newTitle);
                cout << "Enter new task description: ";
                getline(cin, newDescription);
                taskManager.updateTask(title, newTitle, newDescription);
                break;
            }
            case 4: {
                string title;
                cout << "Enter task title to delete: ";
                getline(cin, title);
                taskManager.deleteTask(title);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
