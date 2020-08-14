#include <bits/stdc++.h>

#include "StudentDuesController.h"
#include "Student.h"

using namespace std;

bool StudentDuesController::open(Student student) {

    system("clear");
    double dues = student.getDues();
    showStudentDues(dues);
    int input = getValidInput();
    switch(input){
        case 1 :{
            this->payDues(student);
            return this->open(student);
        }
        case 2 :{
            return this->backToHomepage();
        }
        case 3 :{
            return this->logout();
        }
    }

}

void StudentDuesController::showStudentDues(double dues) {

    cout<<"Your Dues : "<<dues<<"\n\n";
    cout<<"Press 1 to pay dues\n\n";
    cout<<"Press 2 to go back to homepage\n\n";
    cout<<"Press 3 to logout\n\n";

}

int StudentDuesController::getValidInput() {
    
    
    
    string x;
    cin>>ws;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='3' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid input: ";
        return getValidInput();
    }
    
}


double StudentDuesController::getAmountToPay(double dues) {
    string ip;
    cin>>ws;
    getline(cin,ip);
    
    double x=0;
    
    for(int i=0;i<ip.size();i++){
        if(ip[i]>='0' && ip[i]<='9'){
            x*=10;
            x+=ip[i]-'0';
        }
        else{
            cout<<"Please enter valid integral input : \t";
            return getAmountToPay(dues);
        }
    }
    while(x<0 || x>dues){
        cout<<"Please enter valid input in range 0 to "<<dues<<" \t";
        return getAmountToPay(dues);
    }
    return x;
    
}


void StudentDuesController::payDues(Student student) {

    cout<<"Enter Amount to be paid : ";
    double amount = getAmountToPay(student.getDues());
    student.clearDues(amount);

}

bool StudentDuesController::logout() {

    return 0;

}

bool StudentDuesController::backToHomepage() {

    return 1;

}
