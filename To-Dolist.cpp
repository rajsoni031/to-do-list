#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task
{
private:
    string description;
    bool completed;

public:
    Task(string desc)
    {
        description = desc;
        completed = false;
    }

    void markCompleted()
    {
        completed = true;
    }

    string getDescription() const
    {
        return description;
    }

    string getStatus() const
    {
        return completed ? "Completed" : "Pending";
    }
};

class ToDoList
{
private:
    vector<Task> tasks;

public:
    void addTask()
    {
        cin.ignore();
        string desc;
        cout << "Enter task description: ";
        getline(cin, desc);
        tasks.push_back(Task(desc));
        cout << "Task added successfully!\n";
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "\nNo tasks found!\n";
        }
        else
        {
            cout << "\nYour Tasks:\n";
            for (size_t i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". " << tasks[i].getDescription()
                     << " [" << tasks[i].getStatus() << "]\n";
            }
        }
    }

    void markTaskCompleted()
    {
        viewTasks();
        if (!tasks.empty())
        {
            int choice;
            cout << "\nEnter task number to mark as completed: ";
            cin >> choice;
            if (choice >= 1 && choice <= (int)tasks.size())
            {
                tasks[choice - 1].markCompleted();
                cout << "Task marked as completed!\n";
            }
            else
            {
                cout << "Invalid task number!\n";
            }
        }
    }

    void removeTask()
    {
        viewTasks();
        if (!tasks.empty())
        {
            int choice;
            cout << "\nEnter task number to remove: ";
            cin >> choice;
            if (choice >= 1 && choice <= (int)tasks.size())
            {
                cout << "Task '" << tasks[choice - 1].getDescription()
                     << "' removed successfully!\n";
                tasks.erase(tasks.begin() + (choice - 1));
            }
            else
            {
                cout << "Invalid task number!\n";
            }
        }
    }
};

int main()
{
    ToDoList todo;
    int choice;

    while (true)
    {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            todo.addTask();
            break;
        case 2:
            todo.viewTasks();
            break;
        case 3:
            todo.markTaskCompleted();
            break;
        case 4:
            todo.removeTask();
            break;
        case 5:
            cout << "Exiting... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
