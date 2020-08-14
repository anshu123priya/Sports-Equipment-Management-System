#include <bits/stdc++.h>

#include "ViewByOutstandingController.h"
#include "OutstandingEquipments.h"

using namespace std;

bool ViewByOutstandingController::open() {

    system("clear");
    vector<string> equipmentCategory, equipmentID, roll, issueDate, returnDate;
    this->getOutstandingList(equipmentCategory, equipmentID, roll, issueDate, returnDate);
    this->showOutStandingList(equipmentCategory, equipmentID, roll, issueDate, returnDate);
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

void ViewByOutstandingController::getOutstandingList(vector<string> &equipmentCategory, vector<string> &equipmentId, vector<string> &roll, vector<string> &issueDate, vector<string> &returnDate) {

    OutstandingEquipments o;
    o.getCompleteList(equipmentCategory, equipmentId, roll, issueDate, returnDate);

}

void ViewByOutstandingController::showOutStandingList(vector<string> equipmentCategory, vector<string> equimentId, vector<string> roll, vector<string> issueDate, vector<string> returnDate) {
    
    cout<<setw(20)<<"Equipment Category"<<setw(20)<<"Equipment Id"<<setw(20)<<"Roll Number"<<setw(20)<<"Issue Date"<<setw(20)<<"Return Date\n\n";
    for(int i=0;i<equipmentCategory.size();i++){
        cout<<setw(20)<<equipmentCategory[i]<<setw(20)<<equimentId[i]<<setw(20)<<roll[i]<<setw(20)<<issueDate[i]<<setw(20)<<returnDate[i]<<"\n\n";
    }
    cout<<"\n";
    cout<<"Enter 1 to Go back\n\n";
    cout<<"Enter 2 to logout\n\n";
    
}


bool ViewByOutstandingController::logout() {

    return false;

}

bool ViewByOutstandingController::goBackToViewDetails() {

    return true;

}

int ViewByOutstandingController::getValidInput(){



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
