#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
#include <iostream>

class Student : public User
{
    public:
        Student(std::string name, int id);


        void genericAction() override;
        void getUserType() override;

        void matricularClase();

    private:
        int credits;

};

#endif // STUDENT_H
