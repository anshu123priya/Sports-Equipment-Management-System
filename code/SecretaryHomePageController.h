#ifndef UNTITLED_SECRETARYHOMEPAGECONTROLLER_H
#define UNTITLED_SECRETARYHOMEPAGECONTROLLER_H

#include<string>

#include "Student.h"
#include "StudentHomePageController.h"

using namespace std;



class SecretaryHomePageController : public StudentHomePageController {
public:
    bool open(Student secretary);
    void showSecretaryHomePage();
    int getValidInput();
    bool viewDetails();
    bool viewDuesOfStudent();
    bool addEquipment();


};


#endif //UNTITLED_SECRETARYHOMEPAGECONTROLLER_H
