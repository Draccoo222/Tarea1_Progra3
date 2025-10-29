#include "teacher.h"
#include <iostream>


using std::string;
using std::cout;
using std::endl;

Teacher::Teacher(string name, int id, int hwNum): User(){
    this-> name = name;
    this-> id = id;
    this->gradedHw = hwNum;
    blocked = false;
}


void Teacher::getUserType(){
    cout << "Name: " << name << " Id: " << id << endl;
    cout << "User Type: Teacher" << endl;
    cout << "Blocked: " << (blocked ? "Yes" : "No") << endl;
}


void Teacher::genericAction(){
    if(!blocked){
        cout << name << " Is Grading..." << endl;
    }else{
        cout << "Error, user is blocked from any action" << endl;
    }
}

void Teacher::gradeHw(Student* u){
    if(!blocked){
        if(u != 0){
            if(!u->isGraded() && !u->isBlocked()){
                cout << name << " Graded a Homework" << endl;
                u->grade();
                gradedHw++;
                cout << "Total Graded Homeworks: " << gradedHw << endl;
            }else{
                cout << "Error, student is already Graded or is Blocked!" << endl;
            }
        }else{
        cout << "Error, User doesnt exist" << endl;
        }
    }else{
        cout << "Error, this user is blocked from any action" << endl;
    }
}

