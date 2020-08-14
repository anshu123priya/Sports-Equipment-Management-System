#include <bits/stdc++.h>

#include "StudentIssueEquipmentController.h"
#include "OutstandingEquipments.h"
//#include "OutstandingEquipments.cpp"
#include "TotalEquipments.h"
//#include "TotalEquipments.cpp"
#include "AvailableEquipments.h"
//#include "AvailableEquipments.cpp"
#include "Guard.h"
//#include "Guard.cpp"
#include "Student.h"
//#include "Student.cpp"

using namespace std;

bool StudentIssueEquipmentController::open(Student student) {

    system("clear");
    vector<string>equipmentCategory;
    if(!this->checkDue(student) || !this->canIssue(student)) {
        if(!this->checkDue(student)){
            this->showMessage("Please Clear Previous Dues\n\n");
        }
        else{
            this->showMessage("You have already issued Five Equipments\n\n");
        }
        this->showEquipmentList(equipmentCategory);
        int type = this->getValidInput(2);
        switch(type){
            case 1:{
                return this->backToHomepage();
            }
            case 2:{
                return this->logout();
            }
        }
    }
    else{
        this->getAvailableEquipments(equipmentCategory,student);
        int n = equipmentCategory.size();
        if(n==0){
            this->showMessage("No Equipments are Available to Issue\n\n");
        }
        this->showEquipmentList(equipmentCategory);
        int type = this->getValidInput(n+2);
        if(type==n+1){
            return this->backToHomepage();
        }
        else if(type==n+2){
            return this->logout();
        }
        else{

            if(this->guardVerification()) {

                vector<string> equipmentRequested, equipmentId, issueDate;
                equipmentRequested.push_back(equipmentCategory[type - 1]);
                this->getEquipmentData(equipmentRequested, equipmentId, issueDate);
                this->changeEquipmentData(equipmentRequested, equipmentId, student, issueDate);
                this->showMessage("Equipments issued successfully !!\n\nPress 1 to Continue..");
                this->getValidInput(1);
                return this->open(student);
            }
            else{
                this->showMessage("Guard is not Verified, Try Again\n\nPress 1 to continue..");
                this->getValidInput(1);
                return this->open(student);
            }
        }
    }

}

bool StudentIssueEquipmentController::checkDue(Student student) {

    double dues = student.getDues();
    if(dues ==0 )
        return true;
    return false;

}

void StudentIssueEquipmentController::showMessage(string show) {

    cout<<show;

}

int StudentIssueEquipmentController::getValidInput(int n) {
    
    
    
    string x;
    cin>>ws;
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
        cout<<"Please enter valid input: ";
        return getValidInput(n);
    }
    
}



void StudentIssueEquipmentController::showEquipmentList(vector<string> equipmentCategory) {

    for(int i=1;i<=equipmentCategory.size();i++){
        cout<<"Enter "<<i<<" to issue "<<equipmentCategory[i-1]<<"\n\n";
    }
    int n = equipmentCategory.size();
    cout<<"Enter "<<n+1<<" to go back to Homepage\n\n";
    cout<<"Enter "<<n+2<<" to logout\n\n";

}

void StudentIssueEquipmentController::showFinalEquipmentsList(vector<string> equipmentCategory) {



}

void StudentIssueEquipmentController::getAvailableEquipments(vector<string> &equipmentCategory, Student student) {
    
    cout<<"Please wait fetching available list for you.\n\n";
    TotalEquipments myTotalEquipments;
    OutstandingEquipments myOutstandingEquipments;
    AvailableEquipments myAvailableEquipments;
    myTotalEquipments.getEquipmentList(equipmentCategory);
    for(int i=0;i<equipmentCategory.size();i++){
        if(myAvailableEquipments.equipmentAvailable(equipmentCategory[i]) && !myOutstandingEquipments.removeOutStanding(equipmentCategory[i],student)){}
        else{
            equipmentCategory.erase(equipmentCategory.begin()+i);
            i--;
        }
    }
    system("clear");

}

void StudentIssueEquipmentController::getEquipmentData(vector<string> &equipmentCategory, vector<string> &equipmentId, vector<string> &issueDate) {

    AvailableEquipments myAvailableEquipments;
    OutstandingEquipments myOutstandingEquipments;
    for(int i=0;i<equipmentCategory.size();i++){
        string id = myAvailableEquipments.getId(equipmentCategory[i]);
        string Date = myOutstandingEquipments.getTodayDate();
        equipmentId.push_back(id);
        issueDate.push_back(Date);
    }

}

bool StudentIssueEquipmentController::guardVerification() {
    
    cout<<"Enter Password to verify guard : ";
    
    Guard guard;
    string password;
    cin>>ws;
    getline(cin,password);
    int x= guard.verifyGuard(password);
    
    return x;
}


void StudentIssueEquipmentController::changeEquipmentData(vector<string> equipmentCategory, vector<string> equipmentId, Student student, vector<string> Date) {

    AvailableEquipments myAvailableEquipments;
    OutstandingEquipments myOutstandingEquipments;
    myOutstandingEquipments.addToOutStandingData(equipmentCategory, equipmentId, student, Date);
    myAvailableEquipments.removeFromData(equipmentId);

}

bool StudentIssueEquipmentController::logout() {

    return false;

}

bool StudentIssueEquipmentController::backToHomepage() {

    return true;

}

bool StudentIssueEquipmentController::canIssue(Student student) {

    OutstandingEquipments myOutstandingEquipments;
    int alreadyIssued = myOutstandingEquipments.issuedByStudent(student);
    if(alreadyIssued<5)
        return true;
    return false;

}



