#include<bits/stdc++.h>

#include "ViewByAvailabilityController.h"
#include "AvailableEquipments.h"

using namespace std;

bool ViewByAvailabilityController::open() {

    system("clear");
    vector<string> equipmentCategory;
    vector<int> equipmentCount;
    this->getAvailabilityList(equipmentCategory,equipmentCount);
    this->showEquipmentList(equipmentCategory,equipmentCount);
    int type;
    type = this->getValidInput();
    switch(type){
        case 1:{
            return this->goBackToViewDetails();
        }
        case 2:{
            return this->logout();
        }
    }

}

void ViewByAvailabilityController::getAvailabilityList(vector<string> &equipmentCategory, vector<int> &equipmentCount) {

    AvailableEquipments a;
    a.getCompleteList(equipmentCategory,equipmentCount);

}

void ViewByAvailabilityController::showEquipmentList(vector<string> equipmentCategory,vector<int> equipmentCount) {
    
    cout<<setw(20)<<"Equipment Category"<<setw(20)<<"Equipment Count\n\n";
    for(int i=0;i<equipmentCategory.size();i++){
        cout<<setw(20)<<equipmentCategory[i]<<setw(20)<<equipmentCount[i]<<"\n";
    }
    cout<<"\n\n";
    cout<<"Enter 1 to go back\n\n";
    cout<<"Enter 2 to logout\n\n";
    
}


bool ViewByAvailabilityController::logout() {

    return false;

}

bool ViewByAvailabilityController::goBackToViewDetails() {

    return true;

}

int ViewByAvailabilityController::getValidInput(){



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='2' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput();
    }

}
