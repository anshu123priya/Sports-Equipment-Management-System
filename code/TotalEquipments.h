#ifndef UNTITLED_TOTALEQUIPMENTS_H
#define UNTITLED_TOTALEQUIPMENTS_H

#include <string>
#include <vector>

using namespace std;

class TotalEquipments {
public:
    void totalEquipments();
    void getEquipmentList(vector<string> &equipments);
    double getPrice(string equipment);
    string validId();
    void updateId(string equipmentcategory);
};


#endif //UNTITLED_TOTALEQUIPMENTS_H
