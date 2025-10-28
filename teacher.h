#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "student.h"
#include "user.h"


class Teacher: public User
{
    public:
        Teacher(std::string name, int id, int initialHw);

        void genericAction() override;
        void getUserType() override;


        void gradeHw(Student* u);

    private:
        int gradedHw;

};

#endif // TEACHER_H
