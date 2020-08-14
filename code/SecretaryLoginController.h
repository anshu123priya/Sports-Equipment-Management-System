#ifndef UNTITLED_SECRETARYLOGINCONTROLLER_H
#define UNTITLED_SECRETARYLOGINCONTROLLER_H

#include<string>

#include"Student.h"

using namespace std;

class SecretaryLoginController {
public:
    bool open(Student secretary);
    void showSecretaryLogin(string show);
    bool loginSuccess(Student secretary);
    bool loginFail(Student secretary);
};


#endif //UNTITLED_SECRETARYLOGINCONTROLLER_H
