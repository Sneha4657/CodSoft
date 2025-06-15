
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string name;
    bool completed;
};


vector<Task> tasks;


void viewTasks() {
    if (tasks.empty()) {
        cout << "\n📭 Your to-do list is empty!\n" << endl;
        return;
    }

    cout << "\n📋 Your To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name
             << " - " << (tasks[i].completed ? "✅ Completed" : "❌ Pending") << endl;
    }
    cout << endl;
}


void addTask() {
    string taskName;
    cout << "Enter the task you want to add: ";
    cin.ignore(); 
    getline(cin, taskName);

    if (!taskName.empty()) {
        Task newTask = { taskName, false };
        tasks.push_back(newTask);
        cout << "🆕 Task '" << taskName << "' added successfully!\n" << endl;
    } else {
        cout << "⚠️ Task name cannot be empty!\n" << endl;
    }
}


void markTaskCompleted() {
    viewTasks();
    if (tasks.empty()) return;

    int taskNumber;
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= (int)tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "✅ Task '" << tasks[taskNumber - 1].name << "' marked as completed!\n" << endl;
    } else {
        cout << "❌ Invalid task number!\n" << endl;
    }
}


void removeTask() {
    viewTasks();
    if (tasks.empty()) return;

    int taskNumber;
    cout << "Enter the number of the task to remove: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= (int)tasks.size()) {
        cout << "🗑️ Task '" << tasks[taskNumber - 1].name << "' removed.\n" << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        cout << "❌ Invalid task number!\n" << endl;
    }
}


int main() {
    int choice;

    cout << "🎓 Welcome to the Student To-Do List Manager 🎓\n" << endl;

    while (true) {
        cout << "What would you like to do?" << endl;
        cout << "1. View tasks" << endl;
        cout << "2. Add task" << endl;
        cout << "3. Mark task as completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "👋 Bye! Study well and finish your tasks!" << endl;
                return 0;
            default:
                cout << "⚠️ Invalid choice! Try again.\n" << endl;
        }
    }

    return 0;
}
