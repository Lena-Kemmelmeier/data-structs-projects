//Author: Erin Keith
//Date: 6/5/23
//Purpose: HW 2

#include <iostream>
#include <string>
using namespace std;

#include "linkedlist.h"
#include "arraylist.h"

int getMenuChoice();
void displayList(ListInterface<string>&);
void completeTodoTask(LinkedList<string>&, ArrayList<string>&);
void addTodoTask(LinkedList<string>&);

using namespace std;

int main(void){
    int menuChoice;
    LinkedList<string> todoList;
    ArrayList<string> doneList;

    do {
        menuChoice = getMenuChoice();

        switch(menuChoice){
            case 1:
                addTodoTask(todoList);
                break;
            case 2:
                completeTodoTask(todoList, doneList);
                break;
            case 3:
                cout << endl << "To Do: " << endl;
                displayList(todoList);
                break;
            case 4:
                cout << endl << "Completed: " << endl;
                displayList(doneList);
                break;
            case 0:
                break;
            default:
                cout << endl << "Invalid option!" << endl;
                break;
        }
    }while(menuChoice != 0);

    return 0;
}

int getMenuChoice(){
    int userChoice;

    cout << endl << "TODO APP" << endl;
    cout << "1. Add task to do" << endl;
    cout << "2. Complete task" << endl;
    cout << "3. Display TODO list" << endl;
    cout << "4. Display DONE list" << endl;
    cout << "0. Exit " << endl;

    cin >> userChoice;
    return userChoice;
}

void displayList(ListInterface<string>& list){
    if(list.isEmpty()){
        cout << "No tasks currently!" << endl;
        return;
    }

    for(int pos = 1; pos <= list.getLength(); pos++){
        cout << pos << ": " << list.getEntry(pos) << endl;
    }
}

void completeTodoTask(LinkedList<string>& todo, ArrayList<string>& done){
    int pos;
    string completedTask;

    cout << endl << "To Do: " << endl;
    displayList(todo);

    if(!todo.isEmpty()){
        cout << "Please select which task you've completed: " << endl;
        cin >> pos;

        try{
            completedTask = todo.getEntry(pos);
        }
        catch(const char* e){
            cout << endl << "Could not complete task." << endl;
            return;
        }

        todo.remove(pos);

        if(todo.isEmpty()){
            cout << endl << "GREAT JOB! You finished all your tasks :D";
        }

        cout << endl << "Completed: " << endl;
        done.insert(done.getLength() + 1, completedTask);
        displayList(done);
    }
}

void addTodoTask(LinkedList<string>& todo){
    int priority;
    string newTask;

    displayList(todo);

    cout << endl << "What is the priority of your new task?" << endl;
    cin >> priority;

    while(priority < 1 || priority > todo.getLength() + 1){
        cout << "Choose a priority 1 through " << todo.getLength() + 1 << endl;
        cin >> priority;
    }

    cout << "What is your new task?" << endl;
    getline(cin, newTask);
    getline(cin, newTask);

    todo.insert(priority, newTask);
}