#include<bits/stdc++.h>

#include "AddEquipmentController.h"
#include "TotalEquipments.h"
#include "AvailableEquipments.h"

using namespace std;

bool AddEquipmentController::open() {

    system("clear");
    vector<string> equipmentCategory;
    this->getEquipmentList(equipmentCategory);
    this->showEquipmentList(equipmentCategory);
    int n = equipmentCategory.size();
    int type = this->getValidInput(n);
    if(type==n+1){
        return this->backToHomePage();
    }
    else if(type==n+2){
        return this->logout();
    }
    else{
        system("clear");
        this->showMesage("Please Enter Quantity to be added : ",0);
        int quantity = this->getQuantity();
        vector<string>equipmentId;

        TotalEquipments myTotalEquipments;

        for(int i=0;i<quantity;i++){
            string id = this->getId();
            equipmentId.push_back(id);
            myTotalEquipments.updateId(equipmentCategory[type-1]);

        }
        this->addEquipment(equipmentCategory[type-1], equipmentId);
        this->showMesage("Equipments Added Successfully !!\n\n",1000000000);
        return this->open();
    }

}

void AddEquipmentController::getEquipmentList(vector<string> &equipmentCategory) {

    TotalEquipments myTotalEquipments;
    myTotalEquipments.getEquipmentList(equipmentCategory);

}

void AddEquipmentController::showEquipmentList(vector<string> equipmentCategory) {

    for(int i=1;i<=equipmentCategory.size();i++){
        cout<<"Press "<<i<<" to add "<<equipmentCategory[i-1]<<"\n\n";
    }
    int n = equipmentCategory.size();
    cout<<"Press "<<n+1<<" to go back to Homepage\n\n";
    cout<<"Press "<<n+2<<" to logout\n\n";

}

void AddEquipmentController::showMesage(string message, int pause) {

    cout<<message;
    for(int i=0;i<=pause;i++){

    }

}

int AddEquipmentController::getValidInput(int n) {



    n+=2;
    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return this->getValidInput(n-2);
    }
    else if(x[0]<=n+'0' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        cout<<"Please enter valid input : ";
        return getValidInput(n-2);
    }

}

int AddEquipmentController::getQuantity() {
    string ip;
    int quantity=0;
    cin>>ws;
    getline(cin,ip);
    for(int i=0;i<ip.size();i++){
        if(ip[i]>='0' && ip[i]<='9'){
            quantity*=10;
            quantity+=(ip[i]-'0');
        }
        else{
            cout<<"Please enter valid input : \n";
            return getQuantity();
        }
    }
    while(quantity<0){
        cout<<"Please Enter Valid Quantity : ";
        cin>>quantity;
        cout<<"\n";
    }
    return quantity;
    
}


string AddEquipmentController::getId() {

    TotalEquipments myTotalEquipments;
    string id = myTotalEquipments.validId();
    return id;

}

void AddEquipmentController::addEquipment(string equipmentCategory, vector<string> equipmentId) {

    AvailableEquipments myAvailableEquipments;
    myAvailableEquipments.addEquipment(equipmentCategory, equipmentId);

}

bool AddEquipmentController::logout() {

    return false;

}

bool AddEquipmentController::backToHomePage() {

    return true;

}
