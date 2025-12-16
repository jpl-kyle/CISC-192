#include <iostream>
#include <string>
using namespace std;

class Task {
private:
    int id;
    string description;
    bool completed = false;

public:
    Task() : id(0), description("N/A"), completed(false) {};
    Task(int id, const std::string& desc) : id(id), description(desc), completed(false) {};

    void markCompleted(); //sets a task as completed, called by completeTask
    bool isCompleted() const; //checks if the task is completed
    int getId() const; //getter function
    std::string getDescription() const; //getter function
    void printTask(Task* t, int size); //prints the task, acts as listTasks from the prompt
    void completeTask(Task* t); //sets an unfinished task as finished, vice versa.
    void addTask(Task* tasks, int& size, int capacity, const std::string& desc);
    void removeTask(Task* tasks, int& size, int id);
};

int main() { 

    int size = 0; 
    int capacity = 5;
    int input = 0; //for the enum class
    int idInput = 0; //for the remove task function in enum class
    string taskInput = "";
    enum class TaskManager { AddTask=1, RemoveTask=2, SetStatus=3, PrintTasks=4, Exit=5};

    Task* tasks = new Task[capacity];
    
    cout << "Please insert the first task you would like to add:\n";
    getline(cin, taskInput);
    tasks->addTask(tasks, size, capacity, taskInput);

    while (true) {
        cout << "\n"
             << "1 - Add Task" << '\n'
             << "2 - Remove Task" << '\n'
             << "3 - Change Task Status" << '\n'
             << "4 - Print Current Tasks" << '\n'
             << "5 - Exit" << '\n'
             << "Please make your choice: ";

        cin >> input;
        cout << '\n';

        switch (static_cast<TaskManager>(input)) {
            case TaskManager::AddTask: {
                cout << "Enter task description: ";
                cin.ignore(10000, '\n');
                getline(cin, taskInput);
                tasks->addTask(tasks, size, capacity, taskInput);
                break;
            }
            case TaskManager::RemoveTask: {
                cout << "Enter task ID to remove: ";
                cin >> idInput;
                tasks->removeTask(tasks, size, idInput);
                break;
            }
            case TaskManager::SetStatus: {
                cout << "Enter task ID to change status: ";
                cin >> idInput;

                if (idInput > 0 && idInput <= size) {
                    tasks[idInput - 1].completeTask(&tasks[idInput - 1]);
                } 
                else {
                    cout << "Invalid task ID.\n";
                }
                break;
            }
            case TaskManager::PrintTasks: {
                tasks->printTask(tasks, size);
                break;
            }
            case TaskManager::Exit: {
                delete[] tasks;
                tasks = nullptr;
                cout << "Bye!" << '\n';
                return 0;
            }
            default: {
                cout << "Invalid option." << '\n';
            }
        }
    }
}

int Task::getId() const { //retrieves the id of the object
    return id;
};

string Task::getDescription() const {  //retrieves the description of the object
    return description;
};

bool Task::isCompleted() const { //checks if the task is completed
    if (completed == true) {
        return true;
    }
    else {
        return false;
    };
};

void Task::markCompleted() { //marks the task as complete
    if (completed == false){
        completed = true;
    }
    else {
        completed = false;
    };
};

 void Task::completeTask(Task* tasks) {
        if (tasks->isCompleted() == true) { 
            tasks->markCompleted();
            cout << "Task " << tasks->id << ": " << tasks->description << " has been set as unfinished!" << '\n';
        }
        else {
            tasks->markCompleted();
            cout << "Task " << tasks->id << ": " << tasks->description << " has been set as finished!" << '\n';
        };
}; 

void Task::printTask(Task* tasks, int size) {
    if (size == 0) {
        cout << "No tasks to display." << '\n';
        return;
    }      

    for (int i=0; i<size; ++i) {
        cout << "Task " << tasks[i].getId() << ": \"" << tasks[i].getDescription() << "\""
        << (tasks[i].isCompleted() ? " (Finished)" : " (Unfinished)") << '\n';
    }
};

void Task::addTask(Task* tasks, int& size, int capacity, const std::string& desc) {
    if (size >= capacity) {
        cout << "Task limit has been reached! (" << capacity << ")" << '\n';
        return;
    }

    tasks[size] = Task(size + 1, desc);
    cout << "Task \"" << desc << "\" has been assigned to ID #" << size + 1 << "!" << '\n';
    size++;
}

void Task::removeTask(Task* tasks, int& size, int id) {
    if (id <= 0 || id > size) {
        cout << "Invalid task ID.\n";
        return;
    }

    int index = id - 1; // converts id to array index

    for (int i = index; i < size - 1; ++i) { // shifts the tasks left
    tasks[i] = tasks[i + 1];
    tasks[i].id = i + 1;  
    }
    size--; //decrease the size of the array
    cout << "Task ID #" << id << " has been removed.\n";
}

