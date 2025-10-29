#include "usermanager.h"

#include "student.h"
#include "teacher.h"
#include "admin.h"


UserManager::UserManager() {
    users.push_back(new Student("Ana", 101));
    users.push_back(new Student("Luis", 102));
    users.push_back(new Teacher("Prof. Silva", 201, 0));
    users.push_back(new Teacher("Prof. Brown", 202, 0));
    users.push_back(new Admin("Admin-Jefe", 901));
    users.push_back(new Admin("Admin-Sys", 902));
}

void UserManager::printUsers(){
    for(const auto& u: users){
        u->getUserType();
        std::cout << "\n";
    }
}

UserManager::~UserManager(){
    for(auto& u: users){
        delete u;
    }
    users.clear();
}

void UserManager::addUser(std::string name, int id, int co){
    User* tmp = searchUser(id);
    if(tmp == 0){
        users.push_back(new Teacher(name, id, co));
        std::cout << "User added with no problem!" << std::endl;
    }else{
        std::cout << "Error, id is already in use, please try again with another one" << std::endl;
    }
}

void UserManager::addUser(std::string name, int id, bool co){
    User* tmp = searchUser(id);
    if(tmp == 0){
        if(co){
            users.push_back(new Admin(name, id));
        }else{
            users.push_back(new Student(name, id));
        }
        std::cout << "User added with no problem!" << std::endl;
    }else{
        std::cout << "Error, id is already in use, please try again with another one" << std::endl;
    }
}

User* UserManager::searchUser(int id){
    for(const auto& u: users){
        if(u->getId() == id){
            return u;
        }
    }
    return 0;
}
