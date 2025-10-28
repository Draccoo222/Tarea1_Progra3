#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "user.h"

class Admin : public User
{
    public:
        Admin(std::string name, int id);

        void getUserType() override;
        void genericAction() override;


        void blockUser(User* u);

};

#endif // ADMIN_H
