#include <bits/stdc++.h>
#include "ViewByCategoryController.h"
#include "TotalEquipments.h"
#include "AvailableEquipments.h"
#include "OutstandingEquipments.h"

using namespace std;

bool ViewByCategoryController::open() {

    system("clear");
    vector<string>equipmentCategory;
    this->getEquipmentCategory(equipmentCategory);
    this->showList(equipmentCategory);
    int n = equipmentCategory.size();
    int input =  this->getValidInput(n+2);
    if(input == n+1){
        return this->goBackToViewDetails();
    }
    else if(input == n+2){
        return this->logout();
    }
    else{
        system("clear");
        int totalavailable = this->getAvailableList(equipmentCategory[input-1]);
        this->showAvailableList(totalavailable, equipmentCategory[input-1]);
        vector<string> equipmentId, roll, issueDate, returnDate;
        this->getOutStandingList(equipmentCategory[input-1], equipmentId, roll, issueDate, returnDate);
        this->showOutStanding(equipmentCategory[input-1], equipmentId, roll, issueDate, returnDate);
        cout<<"Press 1 to Continue..";
        this->getValidInput(1);
        return this->open();
    }

}

void ViewByCategoryController::showList(vector<string>equipmentCategory) {

    for(int i=1;i<=equipmentCategory.size();i++){
        cout<<"Enter "<<i<<" to view details of "<<equipmentCategory[i-1]<<"\n\n";
    }
    int i = equipmentCategory.size();
    cout<<"Enter "<<i+1<<" to go back\n\n";
    cout<<"Enter "<<i+2<<" to logout\n\n";

}

int ViewByCategoryController::getValidInput(int n) {


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

void ViewByCategoryController::showOutStanding(string equipmentCategory, vector<string> equipmentId, vector<string> roll, vector<string> issueDate, vector<string>returnDate) {
    
    cout<<"List of Outstanding "<<equipmentCategory<<"s is given below : \n\n";
    cout<<setw(20)<<"EquipmentId"<<setw(20)<<"Roll Number"<<setw(20)<<"Issue Date"<<setw(20)<<"Return Date\n\n";
    for(int i=0;i<equipmentId.size();i++){
        cout<<setw(20)<<equipmentId[i]<<setw(20)<<roll[i]<<setw(20)<<issueDate[i]<<setw(20)<<returnDate[i]<<"\n\n";
    }
    
}


void ViewByCategoryController::getOutStandingList(string equipmentCategory, vector<string> &equipmentId, vector<string> &roll, vector<string> &issueDate, vector<string> &returnDate) {

    OutstandingEquipments myOutstandingEquipments;
    myOutstandingEquipments.getListOfOtstanding(equipmentCategory, equipmentId, roll, issueDate, returnDate);

}

int ViewByCategoryController::getAvailableList(string equipmentCategory) {

    AvailableEquipments myAvailableEquipments;
    return myAvailableEquipments.equipmentAvailable(equipmentCategory);

}

void ViewByCategoryController::showAvailableList(int count,string equipmentCategory) {

    cout<<count<<" "<<equipmentCategory<<"s are Available\n\n";

}

bool ViewByCategoryController::logout() {

    return false;

}

bool ViewByCategoryController::goBackToViewDetails() {

    return true;

}

void ViewByCategoryController::getEquipmentCategory(vector<string> &equipmentCategory) {

    TotalEquipments myTotalEquipments;
    myTotalEquipments.getEquipmentList(equipmentCategory);

}
