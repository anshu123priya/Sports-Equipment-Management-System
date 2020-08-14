#include <bits/stdc++.h>

#include "ViewDetailsController.h"
#include "ViewByAvailabilityController.h"
//#include "ViewByAvailabilityController.cpp"
#include "ViewByOutstandingController.h"
//#include "ViewByOutstandingController.cpp"
#include "ViewByCategoryController.h"
//#include "ViewByCategoryController.cpp"
#include "Student.h"

using namespace std;


bool ViewDetailsController::open() {

    system("clear");
    this->showViewDetails();
    int type = this->getValidInput();
    switch(type){
        case 1:{
            if(this->viewByCategory()){
                return this->open();
            }
            else {
                return 0;
            }
        }
        case 2:{
            if(this->viewByOutstanding()){
                return this->open();
            }
            else {
                return 0;
            }
        }
        case 3:{
            if(this->viewByAvailability()){
                return this->open();
            }
            else {
                return 0;
            }
        }
        case 4:{
            return this->backToHomepage();
        }
        case 5:{
            return this->logout();
        }
    }

}

void ViewDetailsController::showViewDetails() {

    cout<<"Enter 1 to view detail by Equipment Category\n\n";
    cout<<"Enter 2 to view detail of all Outstanding Equipments\n\n";
    cout<<"Enter 3 to view detail of all Available Equipments\n\n";
    cout<<"Enter 4 to go back to Homepage\n\n";
    cout<<"Enter 5 to logout\n\n";

}

int ViewDetailsController::getValidInput() {



    string x;
    getline(cin,x);
    if(x.size()>1){
        cout<<"Please enter valid input : ";
        return getValidInput();
    }
    else if(x[0]<='5' && x[0]>='1'){
        int input = x[0]-'0';
        return input;
    }
    else{
        return getValidInput();
    }

}

bool ViewDetailsController::viewByCategory() {

    ViewByCategoryController myViewByCategoryController;
    return myViewByCategoryController.open();

}

bool ViewDetailsController::viewByOutstanding() {

    ViewByOutstandingController myViewByOutstandingController;
    return myViewByOutstandingController.open();

}

bool ViewDetailsController::viewByAvailability() {

    ViewByAvailabilityController myViewByAvailabilityController;
    return myViewByAvailabilityController.open();

}

bool ViewDetailsController::logout() {

    return false;

}

bool ViewDetailsController::backToHomepage() {

    return true;

}
