#include <iostream>
#include <string>
#include <limits>

#include "usermanager.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

int main(int argc, char *argv[]) {

    UserManager* manager = new UserManager();

    std::cout << "Welcome to the User Manager!" << std::endl;
    std::cout << "6 users were pre-loaded." << std::endl;

    bool exit = false;
    int option = 0;

    while (exit == false) {

        std::cout << "\n--- Main Menu ---" << std::endl;
        std::cout << "1. Add User" << std::endl;
        std::cout << "2. List Users (Polymorphic)" << std::endl;
        std::cout << "3. Execute Specific Action (dynamic_cast)" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Select an option: ";

        std::cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            option = -1;
        }

        switch (option) {

        case 1: {
            int type = 0;
            std::cout << "What type? (1. Student, 2. Teacher, 3. Admin): ";
            std::cin >> type;

            if (std::cin.fail() || type < 1 || type > 3) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid type." << std::endl;
                break;
            }

            int id;
            std::string name;

            std::cout << "Enter ID: ";
            std::cin >> id;
            if (std::cin.fail()) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid ID." << std::endl;
                break;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter Name: ";
            std::getline(std::cin, name);

            if (type == 1) {
                manager->addUser(name, id, false);
            }
            else if (type == 2) {
                int hwNum;
                std::cout << "Enter Graded Homeworks (initial): ";
                std::cin >> hwNum;
                if (std::cin.fail()) {

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::cout << "Invalid value." << std::endl;
                    break;
                }
                manager->addUser(name, id, hwNum);
            }
            else if (type == 3) {
                manager->addUser(name, id, true);
            }
            break;
        }
        case 2: {
            std::cout << "\n--- User List ---" << std::endl;
            if (manager->users.empty()) {
                std::cout << "There are no users." << std::endl;
            } else {

                manager->printUsers();
            }
            break;
        }
        case 3: {
            int idActor;
            std::cout << "Enter the ID of the user who will perform the action: ";
            std::cin >> idActor;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid ID." << std::endl;
                break;
            }

            User* actor = manager->searchUser(idActor);

            if (actor == 0) {
                std::cout << "User not found." << std::endl;
                break;
            }

            if (actor->isBlocked()) {
                std::cout << "This user (" << actor->getName() << ") is blocked." << std::endl;
                break;
            }

            std::cout << "\nAttempting action for: " << actor->getName() << std::endl;

            Student* s = dynamic_cast<Student*>(actor);
            if (s != 0) {
                s->genericAction();
                s->addClass();
                break;
            }
            Teacher* t = dynamic_cast<Teacher*>(actor);
            if (t != 0) {
                t->genericAction();
                int idVictim;
                std::cout << "Enter ID of the Student to grade: ";
                std::cin >> idVictim;

                User* victim = manager->searchUser(idVictim);
                Student* s_victim = dynamic_cast<Student*>(victim);

                if (s_victim != 0) {
                    t->gradeHw(s_victim);
                } else {
                    std::cout << "Error: The ID does not belong to a Student." << std::endl;
                }
                break;
            }
            Admin* a = dynamic_cast<Admin*>(actor);
            if (a != 0) {
                a->genericAction();
                int idVictim;
                std::cout << "Enter ID of the User to block: ";
                std::cin >> idVictim;

                User* victim = manager->searchUser(idVictim);
                if (victim != 0) {
                    a->blockUser(victim);
                } else {
                    std::cout << "Error: User to block not found." << std::endl;
                }
                break;
            }
            std::cout << "The user does not have a specific action." << std::endl;
            break;
        }
        case 4:
            exit = true;
            delete manager;
            std::cout << "Exiting... Memory will be cleared automatically." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
        std::cout << std::endl;

    }
    return 0;
}
