//
// Created by Manvendra on 3/29/2018.
//

#ifndef UNTITLED_STUDENTRETURNEQUIPMENTCONTROLLER_H
#define UNTITLED_STUDENTRETURNEQUIPMENTCONTROLLER_H

#include <string.h>
#include <bits/stdc++.h>

#include "Student.h"

using  namespace std;

class StudentReturnEquipmentController {
public:
    bool open(Student student);
    void showMessage(string show);
    void showEquipmentList(vector<string>equipmentCategory);
    void getEquipmentList(vector<string> &equipmentCatgeory, Student student);
    string getEquipmentDetails(string equipmentsCategory, Student student);
    void removeFromOutstanding(string equipmentId);
    void addToAvailable(string equipmentCatgeory, string equipmentId);
    void addDues(Student student, int damaged, string equipmentId, string equipmentCategory);
    bool guardVerificatiion();
    bool logout();
    bool backToHomePage();
    int getValidInput(int n);
};


#endif //UNTITLED_STUDENTRETURNEQUIPMENTCONTROLLER_H
