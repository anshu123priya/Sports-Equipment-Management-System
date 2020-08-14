#ifndef UNTITLED_VIEWDETAILSCONTROLLER_H
#define UNTITLED_VIEWDETAILSCONTROLLER_H
#include<string>

#include "Student.h"

using namespace std;


class ViewDetailsController {
public:
    bool open();
    void showViewDetails();
    int getValidInput();
    bool viewByCategory();
    bool viewByOutstanding();
    bool viewByAvailability();
    bool logout();
    bool backToHomepage();
};


#endif //UNTITLED_VIEWDETAILSCONTROLLER_H
