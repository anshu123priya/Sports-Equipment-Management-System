#include <bits/stdc++.h>

#include "SecretaryLoginController.h"
#include "Student.h"
#include "SecretaryHomePageController.h"
//#include "SecretaryHomePageController.cpp"

using namespace std;

bool SecretaryLoginController::open(Student secretary) {
    
    system("clear");
    string secretaryUserName;
    string secretaryPassword;
    
    this->showSecretaryLogin("Username");
    getline(cin,secretaryUserName);
    
    this->showSecretaryLogin("Password");
    getline(cin,secretaryPassword);
    
    bool matchdetails = secretary.matchDetailsSecretary(secretaryUserName,secretaryPassword);
    if(matchdetails){
        return this->loginSuccess(secretary);
    }
    else{
        return this->loginFail(secretary);
    }
    
}


void SecretaryLoginController::showSecretaryLogin(string show) {

    cout<<"Please Enter "<<show<<" : ";

}

bool SecretaryLoginController::loginSuccess(Student secretary) {

    SecretaryHomePageController mySecretaryHomePageController;
    return mySecretaryHomePageController.open(secretary);

}

bool SecretaryLoginController::loginFail(Student secretary) {

    system("clear");
    cout<<"Your Details didn't match with our Database\n";
    for(int i=0;i<1000000000;i++){}
    return true;

}
