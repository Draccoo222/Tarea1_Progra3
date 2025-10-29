#include "student.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

Student::Student(string name, int id): User() {
    this->name = name;
    this->id = id;
    this->credits = 10;
    graded = false;
}

bool Student::isGraded(){
    return graded;
}


void Student::getUserType(){
    cout << "Name: " << name << " Id: " << id << endl;
    cout << "User Type: Student" << endl;
    cout << "Blocked: " << (blocked ? "Yes" : "No") << endl;
}

void Student::genericAction(){
    if(!blocked){
        cout << name << " Is studying" << endl;
    }else{
        cout << "Error, user is blocked from any action" << endl;
    }
}

void Student::grade(){
    if(!blocked){
        graded = true;
    }else{
        cout << "Error, cant grade a blocked user" << endl;
    }
}

void Student::addClass(){
    if(!blocked){
        if(credits > 0){
            cout << "Student " << name << " Added a new class to their schedule" << endl;
            credits--;
            cout << "Credits Left: " << credits << endl;
        }else{
            cout << "Error, not enough credits left to add a class!" << endl;
        }
    }else{
        cout << "Error, user is blocked from any action" << endl;
    }
}




