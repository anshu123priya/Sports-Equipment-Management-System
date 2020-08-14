#ifndef UNTITLED_STUDENTHOMAPAGECONTROLLER_H
#define UNTITLED_STUDENTHOMAPAGECONTROLLER_H

#include <string>

#include "Student.h"

using namespace std;


class StudentHomePageController {
public:
    bool open(Student student);
    void showStudentHomePage();
    int getVaildInput();
    bool issueEquipment(Student student);
    bool returnEquipment(Student student);
    bool checkDues(Student student);
    bool logout();
    bool exit();

};


#endif //UNTITLED_STUDENTHOMAPAGECONTROLLER_H
