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

    void markCompleted(); //setter function
    bool isCompleted() const; //checks if the task is completed
    int getId() const; //getter function
    std::string getDescription() const; //getter function
    void printTask(Task* t); //prints the task
    void completeTask(Task* t);
    
};

int main() { 
    Task t1(1, "Finish project"); // ID: 1, Description: Finish project
    Task t2(2, "Study for exam"); // ID: 2, Description: Study for exam

    Task* p1 = &t1; // Task object pointer "p1" is set to the address of Task 1
    Task* p2 = &t2; // Task object pointer "p2" is set to the address of Task 2

    /* guidelines for myself
    cout << "Pointer 1 address: " << &p1
    << " Pointer 1 value: " << p1 // Pointer 1 == the memory address of Task 1
    << " Task 1's address: " << &t1 << '\n';
    
    cout << "Pointer 2 address: " << &p2
    << "Pointer 2 value: " << p2 // Pointer 2 == the memory address of Task 2
    << " Task 2's address: " << &t2 << '\n';

    cout << "Pointer 1 id: " << p1->getId() << ", is equal to Task 1's id, " << t1.getId() << "." << '\n'; //p1 points to t1's getId
    cout << "Pointer 1 desc: " << p1->getDescription() << ", is equal to Task 1's desc," << t1.getDescription() << "." << '\n';
    cout << "Pointer 2 id: " << p2->getId() << ", is equal to Task 2's id, " << t2.getId() << "." << '\n'; // p2 points to t1's getId
    cout << "Pointer 2 desc: " << p2->getDescription() << ", is equal to Task 2's desc," << t2.getDescription() << "." << '\n';
    */

    p1->printTask(p1);
    p1->completeTask(p1);
    p1->printTask(p1);

    p2->printTask(p2);
    p2->completeTask(p2);
    p2->printTask(p2);
    

    return 0;
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

 void Task::completeTask(Task* t) {
        if (t->isCompleted() == true) {
            t->markCompleted();
            cout << "Task " << t->id << ": " << t->description << " has been set as unfinished!" << '\n';
        }
        else {
            t->markCompleted();
            cout << "Task " << t->id << ": " << t->description << " has been set as finished!" << '\n';
        };
}; 

void Task::printTask(Task* t) {
    if (t->isCompleted() == true) {
        cout << "Task " << t->id << ": " << t->description << " (Finished)" << '\n';
    }
    else {
        cout << "Task " << t->id << ": " << t->description << " (Unfinished)" << '\n';
    };
};

