//
// Created by Manvendra on 3/29/2018.
//

#ifndef UNTITLED_ADDEQUIPMENTCONTROLLER_H
#define UNTITLED_ADDEQUIPMENTCONTROLLER_H

#include <string>
#include<vector>

#include "Student.h"

using namespace std;

class AddEquipmentController {
public:
    bool open();
    void getEquipmentList(vector<string> &equipmentCategory);
    void showEquipmentList(vector<string> equipmentCategory);
    void showMesage(string message, int pause);
    int getValidInput(int n);
    int getQuantity();
    string getId();
    void addEquipment(string equipment,vector<string> equipmentId);
    bool logout();
    bool backToHomePage();
};


#endif //UNTITLED_ADDEQUIPMENTCONTROLLER_H
