#include<bits/stdc++.h>

#include "StudentLoginController.h"
#include "StudentHomePageController.h"
//#include "StudentHomePageController.cpp"
#include "Student.h"

using namespace std;

bool StudentLoginController::open(Student student) {
    
    system("clear");
    string studentUserName;
    string studentPassword;
    
    this->showStudentLogin("Username");
    cin>>ws;
    getline(cin,studentUserName);
    
    this->showStudentLogin("Password");
    cin>>ws;
    getline(cin,studentPassword);
    
    bool matchdetails= student.matchDetailsStudent(studentUserName,studentPassword);
    if(matchdetails){
        return this->loginSuccess(student);
    }
    else{
        return this->loginFail(student);
    }
    
}


void StudentLoginController::showStudentLogin(string show) {

    cout<<"Please Enter "<<show<<" : ";

}

bool StudentLoginController::loginSuccess(Student student) {

    StudentHomePageController myStudentHomePageController;
    return myStudentHomePageController.open(student);

}

bool StudentLoginController::loginFail(Student student) {

    system("clear");
    cout<<"Your Details didn't match with our Database\n";
    for(int i=0;i<1000000000;i++){}
    return 1;

}
