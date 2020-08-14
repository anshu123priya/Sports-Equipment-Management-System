#ifndef UNTITLED_STUDENTLOGINCONTROLLER_H
#define UNTITLED_STUDENTLOGINCONTROLLER_H

#include<string>

#include "Student.h"

using namespace std;

class StudentLoginController {

public:
    bool open(Student student);
    void showStudentLogin(string show);
    bool loginSuccess(Student student);
    bool loginFail(Student student);

};


#endif //UNTITLED_STUDENTLOGINCONTROLLER_H
