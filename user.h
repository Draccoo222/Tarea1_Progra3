#ifndef USER_H
#define USER_H
#include <iostream>
class User
{
    public:
        User(std::string name, int id);

        int getId();
        std::string getName();
        bool isBlocked();

        virtual void getUserType() = 0;
        virtual void genericAction() = 0;

        virtual ~User();
    protected:
        std::string name;
        int id;
        bool blocked;
};

#endif // USER_H
