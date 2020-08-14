#include <bits/stdc++.h>
#include "StudentReturnEquipmentController.h"
#include "TotalEquipments.h"
#include "OutstandingEquipments.h"
#include "AvailableEquipments.h"
#include "Guard.h"
#include "Student.h"

using namespace std;

bool StudentReturnEquipmentController::open(Student student) {

    system("clear");
    vector<string>equipmentCategory;
    this->getEquipmentList(equipmentCategory, student);
    int n = equipmentCategory.size();
    if(n==0){
        this->showMessage("No Equipments are issued by you\n\n");
    }
    this->showEquipmentList(equipmentCategory);
    int type = this->getValidInput(n+2);
    if(type==n+1){
        return this->backToHomePage();
    }
    else if(type==n+2){
        return this->logout();
    }
    else{
        string equipmentId = this->getEquipmentDetails(equipmentCategory[type-1],student);
        if(this->guardVerificatiion()){
            this->showMessage("Enter 1 if Equipment is damaged\n\nEnter 2 if Equipment is not damaged\n\n");
            int damaged = this->getValidInput(2);
            this->addDues(student,damaged,equipmentId,equipmentCategory[type-1]);
            this->removeFromOutstanding(equipmentId);
            if(damaged==2){
                this->addToAvailable(equipmentCategory[type-1],equipmentId);
            }
            this->showMessage("Return was Successfull\n\nPress 1 to Continue..");
            this->getValidInput(2);
            return this->open(student);
        }
        else{
            this->showMessage("Guard is not Verified, PLease Try Again\n\nPress 1 to continue..");
            this->getValidInput(1);
            return this->open(student);
        }
    }

}

void StudentReturnEquipmentController::showMessage(string show) {

    cout<<show;

}

void StudentReturnEquipmentController::showEquipmentList(vector<string> equipmentCategory) {

    for(int i=1;i<=equipmentCategory.size();i++){
        cout<<"Enter "<<i<<" to return "<<equipmentCategory[i-1]<<"\n\n";
    }
    int n = equipmentCategory.size();
    cout<<"Enter "<<n+1<<" to go back to homepage\n\n";
    cout<<"Enter "<<n+2<<" to logout\n\n";

}

void StudentReturnEquipmentController::getEquipmentList(vector<string> &equipmentCatgeory, Student student) {
    
    cout<<"Please wait fetching list.\n\n";
    
    TotalEquipments myTotalEquipments;
    OutstandingEquipments myOutstandingEquipments;
    myTotalEquipments.getEquipmentList(equipmentCatgeory);
    for(int i=0;i<equipmentCatgeory.size();i++){
        if(!myOutstandingEquipments.removeOutStanding(equipmentCatgeory[i],student)){
            equipmentCatgeory.erase(equipmentCatgeory.begin()+i);
            i--;
        }
    }
    system("clear");
}

string StudentReturnEquipmentController::getEquipmentDetails(string equipmentsCategory, Student student) {

    OutstandingEquipments myOutstandingEquipments;
    return myOutstandingEquipments.getId(equipmentsCategory,student);

}

void StudentReturnEquipmentController::removeFromOutstanding(string equipmentId) {

    vector<string>equipmentIds;
    equipmentIds.push_back(equipmentId);
    OutstandingEquipments myOutstandingEquipments;
    myOutstandingEquipments.removeFromOutStanding(equipmentIds);

}

void StudentReturnEquipmentController::addToAvailable(string equipmentCatgeory, string equipmentId) {

    vector<string>equipmentCategories, equipmentIds;
    equipmentCategories.push_back(equipmentCatgeory);
    equipmentIds.push_back(equipmentId);
    AvailableEquipments myAvailableEquipments;
    myAvailableEquipments.addToAvailableData(equipmentCategories, equipmentIds);

}

void StudentReturnEquipmentController::addDues(Student student, int damaged, string equipmentId, string equipmentCategory) {

    double dues = 0;
    OutstandingEquipments myOutstandingEquipments;
    TotalEquipments myTotalEquipments;
    int extra = myOutstandingEquipments.additionalDays(equipmentId);
    if(damaged==1){
       


        dues+=myTotalEquipments.getPrice(equipmentCategory);
        
        student.addDues(dues);
    }
    else{
        dues+= extra*10;
        student.addDues(dues);
    }

}

bool StudentReturnEquipmentController::guardVerificatiion() {
    
    Guard guard;
    string password;
    cout<<"Enter password to verify guard : ";
    cin>>ws;
    getline(cin,password);
    return guard.verifyGuard(password);
    
}


bool StudentReturnEquipmentController::logout() {

    return false;

}

bool StudentReturnEquipmentController::backToHomePage() {

    return true;

}

int StudentReturnEquipmentController::getValidInput(int n) {


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
