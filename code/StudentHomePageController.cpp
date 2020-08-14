#include<bits/stdc++.h>

#include "StudentHomePageController.h"
#include "StudentIssueEquipmentController.h"
//#include "StudentIssueEquipmentController.cpp"
#include "StudentReturnEquipmentController.h"
//#include "StudentReturnEquipmentController.cpp"
#include "StudentDuesController.h"
//#include "StudentDuesController.cpp"
#include "Student.h"

using namespace std;

bool StudentHomePageController::open(Student student) {

    system("clear");
    this->showStudentHomePage();
    int type=this->getVaildInput();
    if(type==1){
        if(this->issueEquipment(student)){
            return this->open(student);
        }
        else{
            return true;
        }
    }
    else if(type==2){
        if(this->returnEquipment(student)){
            return this->open(student);
        }
        else{
            return true;
        }
    }
    else if(type==3){
        if(this->checkDues(student)){
            return this->open(student);
        }
        else{
            return true;
        }
    }
    else if(type==4){
       return this->logout();
    }
    else{
        return this->exit();
    }

}

void StudentHomePageController::showStudentHomePage() {

    cout<<"Enter 1 to issue equipments\n\n";
    cout<<"Enter 2 to return equipments\n\n";
    cout<<"Enter 3 to  check dues \n\n";
    cout<<"Enter 4 to logout \n\n";
    cout<<"Enter 5 to exit\n\n";

}

int StudentHomePageController::getVaildInput() {
    
    
    string x;
    cin>>ws;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input within range : ";
        return getVaildInput();
    }
    else if(x[0]<='5' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid integral input within  range";
        return getVaildInput();
    }
    
}



bool StudentHomePageController::issueEquipment(Student student) {

    StudentIssueEquipmentController myStudentIssueEquipmentController;
    return myStudentIssueEquipmentController.open(student);

}


bool StudentHomePageController::returnEquipment(Student student) {

    StudentReturnEquipmentController myStudentReturnEquipmentController;
    return myStudentReturnEquipmentController.open(student);

}


bool StudentHomePageController::checkDues(Student student) {

    StudentDuesController myStudentDuesController;
    return myStudentDuesController.open(student);

}


bool StudentHomePageController::logout() {

    return 1;

}

bool StudentHomePageController::exit() {

    return 0;

}
