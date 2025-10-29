#include "user.h"
#include <iostream>

using std::cout;
using std::string;
using std::endl;

User::User(){
    id = -1;
    name = "placeHolder";
    blocked = false;
}

User::~User(){}

User::User(string name, int id) {
    this->name = name;
    this->id = id;
    blocked = false;
}

int User::getId(){
    return id;
}

string User::getName(){
    return name;
}

bool User::isBlocked(){
    return blocked;
}

void User::block(){
    blocked = true;
}
