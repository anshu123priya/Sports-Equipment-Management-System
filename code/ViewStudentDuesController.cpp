#include <bits/stdc++.h>
#include "ViewStudentDuesController.h"
#include "Student.h"

using namespace std;

bool ViewStudentDuesController::open() {

    system("clear");
    this->showViewStudentDuesController();
    int type = this->getValidInput(3);
    switch(type){
        case 1:{
            system("clear");
            this->showMessage("Please Enter Student Roll Number : ");
            string roll = this->getRollNumber();
            Student temp;
            if(temp.getDetailsByRoll(roll)){
                double dues = this->getDues(temp);
                string name = this->getName(temp);
                cout<<"Dues of "<<name<<" : "<<dues<<"\n\n";
            }
            else{
                this->showMessage("Entered Roll Number Doesn't Exist\n\n");
            }
            this->showMessage("Press 1 to Continue..");
            this->getValidInput(1);
            return this->open();
        }
        case 2:{
            return this->goBackToHomePage();
        }
        case 3:{
            return this->logout();
        }
    }

}

string ViewStudentDuesController::getRollNumber() {
    
    string roll;
    cin>>ws;
    getline(cin,roll);
    for(int i=0;i<roll.size();i++){
        roll[i]=toupper(roll[i]);
    }
    return roll;
    
}



double ViewStudentDuesController::getDues(Student student) {

    double dues = student.getDues();
    return dues;

}

string ViewStudentDuesController::getName(Student student) {

    string name = student.getName();
    return name;
}

void ViewStudentDuesController::showMessage(string message) {

    cout<<message;

}

bool ViewStudentDuesController::goBackToHomePage() {

    return true;

}

bool ViewStudentDuesController::logout() {

    return false;

}

void ViewStudentDuesController::showViewStudentDuesController() {

    cout<<"Enter 1 to find dues of any student by entering roll number\n\n";
    cout<<"Enter 2 to go back to homepage\n\n";
    cout<<"Enter 3 to logout\n\n";

}

int ViewStudentDuesController::getValidInput(int n) {



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput(n);
    }
    else if(x[0]<=n+'0' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput(n);
    }
}
