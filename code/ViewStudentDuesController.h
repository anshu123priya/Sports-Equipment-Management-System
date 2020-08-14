#ifndef UNTITLED_VIEWSTUDENTDUESCONTROLLER_H
#define UNTITLED_VIEWSTUDENTDUESCONTROLLER_H

#include <string>

#include "Student.h"

using namespace std;


class ViewStudentDuesController {
public:
    bool open();
    string getRollNumber();
    string getName(Student student);
    double getDues(Student student);
    void showMessage(string message);
    void showViewStudentDuesController();
    int getValidInput(int n);
    bool goBackToHomePage();
    bool logout();
};


#endif //UNTITLED_VIEWSTUDENTDUESCONTROLLER_H
