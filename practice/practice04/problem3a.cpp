// problem3a.cpp - Smart Task Manager with Improved Error Handling
#include <iostream>
#include <list>
#include <string>
#include <limits>
using namespace std;

struct Task {
    string description;
    bool completed = false;
};

void showTasks(const list<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available right now.\n";
        return;
    }
    int i = 1;
    for (const auto& task : tasks) {
        cout << i++ << ". " << task.description << (task.completed ? " ?" : "") << "\n";
    }
}

int main() {
    list<Task> tasks;
    int choice;

    while (true) {
        cout << "\nWhat would you like me to do?\n";
        cout << "1. Add Task\n2. Remove Task\n3. Show Tasks\n4. Mark Task Completed\n5. Clear Tasks\n6. Exit\nChoose an option: ";

        while (true) {
            if (!(cin >> choice)) {
                cout << "Error: Invalid input. Please enter a number between 1 and 6.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice < 1 || choice > 6) {
                cout << "Error: Number out of range. Please enter a number between 1 and 6.\n";
                continue;
            }
            break;
        }
        cin.ignore();

        if (choice == 1) {
            Task newTask;
            cout << "What task would you like me to add? ";
            getline(cin, newTask.description);
            tasks.push_back(newTask);
            cout << "Task added.\n";

        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "There are no tasks to remove.\n";
                continue;
            }
            showTasks(tasks);
            int num;
            cout << "Which task number should I remove? ";
            while (true) {
                if (!(cin >> num)) {
                    cout << "Error: Invalid input. Please enter a valid task number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Try again. Enter task number: ";
                    continue;
                }
                if (num < 1 || num >(int)tasks.size()) {
                    cout << "Error: Task number out of range. Please enter a valid task number.\n";
                    continue;
                }
                break;
            }
            auto it = tasks.begin();
            advance(it, num - 1);
            tasks.erase(it);
            cout << "Task removed!\n";

        }
        else if (choice == 3) {
            showTasks(tasks);

        }
        else if (choice == 4) {
            if (tasks.empty()) {
                cout << "There are no tasks to complete.\n";
                continue;
            }
            showTasks(tasks);
            int num;
            cout << "Which task number did you complete? ";
            while (true) {
                if (!(cin >> num)) {
                    cout << "Error: Invalid input. Please enter a valid task number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Try again. Enter task number: ";
                    continue;
                }
                if (num < 1 || num >(int)tasks.size()) {
                    cout << "Error: Task number out of range. Please enter a valid task number.\n";
                    continue;
                }
                break;
            }
            auto it = tasks.begin();
            advance(it, num - 1);
            it->completed = true;
            cout << "Great job! Task marked as completed.\n";

        }
        else if (choice == 5) {
            tasks.clear();
            cout << "All tasks cleared.\n";

        }
        else if (choice == 6) {
            cout << "Goodbye! Stay productive!\n";
            break;
        }
    }

    return 0;
}
