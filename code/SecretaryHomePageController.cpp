
#include <bits/stdc++.h>

#include "SecretaryHomePageController.h"
#include "ViewDetailsController.h"
//#include "ViewDetailsController.cpp"
#include "AddEquipmentController.h"
//#include "AddEquipmentController.cpp"
#include "ViewStudentDuesController.h"
//#include "ViewStudentDuesController.cpp"
#include "Student.h"

using namespace std;

bool SecretaryHomePageController::open(Student secretary) {

    system("clear");
    this->showSecretaryHomePage();
    int type = this->getValidInput();
    switch(type){
        case 1:{
            if(this->issueEquipment(secretary)){
                return this->open(secretary);
            }
            else{
                return true;
            }
        }
        case 2:{
            if(this->returnEquipment(secretary)){
                return this->open(secretary);
            }
            else{
                return true;
            }
        }
        case 3:{
            if(this->checkDues(secretary)){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 4:{
            if(this->viewDuesOfStudent()){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 5:{
            if(this->addEquipment()){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 6:{
            if(this->viewDetails()){
                return this->open(secretary);
            }
            else {
                return true;
            }
        }
        case 7:{
            return this->logout();
        }
        case 8:{
            return this->exit();
        }
    }

}

void SecretaryHomePageController::showSecretaryHomePage() {

    cout<<"Enter 1 to issue equipments\n\n";
    cout<<"Enter 2 to return equipments\n\n";
    cout<<"Enter 3 to check dues \n\n";
    cout<<"Enter 4 to check dues of any student\n\n";
    cout<<"Enter 5 to add Equipments\n\n";
    cout<<"Enter 6 to view details of Equipments\n\n";
    cout<<"Enter 7 to logout \n\n";
    cout<<"Enter 8 to exit\n\n";

}

int SecretaryHomePageController::getValidInput() {
    
    
    
    string x;
    cin>>ws;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getVaildInput();
    }
    else if(x[0]<='8' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid input: ";
        return getVaildInput();
    }
    
    
}


bool SecretaryHomePageController::viewDetails() {

    ViewDetailsController myViewDetailsController;
    return myViewDetailsController.open();

}

bool SecretaryHomePageController::viewDuesOfStudent() {

    ViewStudentDuesController myViewStudentDuesController;
    return myViewStudentDuesController.open();

}

bool SecretaryHomePageController::addEquipment() {

    AddEquipmentController myAddEquipmentController;
    return myAddEquipmentController.open();

}
