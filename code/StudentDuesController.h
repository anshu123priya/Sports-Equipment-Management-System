#ifndef UNTITLED_STUDENTDUESCONTROLLER_H
#define UNTITLED_STUDENTDUESCONTROLLER_H

#include <string>

#include"Student.h"

using namespace std;

class StudentDuesController {
public:
    bool open(Student student);
    void showStudentDues(double dues);
    int getValidInput();
    double getAmountToPay(double dues);
    void payDues(Student student);
    bool logout();
    bool backToHomepage();

};


#endif //UNTITLED_STUDENTDUESCONTROLLER_H
