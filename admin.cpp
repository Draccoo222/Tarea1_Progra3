#include "admin.h"
#include <iostream>


using std::string;
using std::cout;
using std::endl;

Admin::Admin(string name, int id): User(){
    this->name = name;
    this->id = id;
    blocked = false;
}


void Admin::getUserType(){
    cout << "Name: " << name << " Id: " << id << endl;
    cout << "User Type: Admin" << endl;
    cout << "Blocked: " << (blocked ? "Yes" : "No") << endl;
}


void Admin::genericAction(){
    if(!blocked){
        cout << name << " Is Monitoring..." << endl;
    }else{
        cout << "Error, user is blocked from any action" << endl;
    }
}


void Admin::blockUser(User* u){
    if(!blocked){
        if(u !=0){
            if(!u->isBlocked()){
                cout << "Admin has blocked a user with the id of: " << u->getId() << endl;
                u->block();
            }
            cout << "Error, user is already blocked" << endl;
        }else{
            cout << "Error, cant block a null user" << endl;
        }
    }else{
        cout << "Error, user is blocked from any action" << endl;
    }
}
