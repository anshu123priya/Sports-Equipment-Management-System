#ifndef UNTITLED_VIEWBYAVAILABILITYCONTROLLER_H
#define UNTITLED_VIEWBYAVAILABILITYCONTROLLER_H

#include <string>
#include <vector>

using namespace std;

class ViewByAvailabilityController {
public:
    bool open();
    void getAvailabilityList(vector<string> &equipmentCategory,vector<int> &equipmentCount);
    void showEquipmentList(vector<string> equipmentCategory,vector<int> equipmentCount);
    bool logout();
    int getValidInput();
    bool goBackToViewDetails();
};


#endif //UNTITLED_VIEWBYAVAILABILITYCONTROLLER_H
