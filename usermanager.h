#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "user.h"
#include <iostream>
#include <vector>

class UserManager
{
    public:
        UserManager();

        std::vector<User*> users;

        void printUsers();

        void addUser(std::string, int id, int credit);
        void addUser(std::string, int id, bool isAdmin);

        User* searchUser(int id);

        User* curUser = 0;

        virtual ~UserManager();
};

#endif
