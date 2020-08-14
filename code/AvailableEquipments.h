#ifndef UNTITLED_AVAILABLEEQUIPMENTS_H
#define UNTITLED_AVAILABLEEQUIPMENTS_H

#include <bits/stdc++.h>

#include "Student.h"

using namespace std;

class AvailableEquipments {
public:
    void removeFromData(vector<string> equipmentsId);
    int equipmentAvailable(string equipment);
    void addToAvailableData(vector<string> equipments,vector<string> equipmentId);
    void addEquipment(string equipment,vector<string> equimentId);
    void getCompleteList(vector<string> &equipmentCategory,vector<int> &equipmentCount);
    string getId(string equipment);
};


#endif //UNTITLED_AVAILABLEEQUIPMENTS_H
