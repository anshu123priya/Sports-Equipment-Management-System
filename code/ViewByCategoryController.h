#ifndef UNTITLED_VIEWBYCATEGORYCONTROLLER_H
#define UNTITLED_VIEWBYCATEGORYCONTROLLER_H


#include <vector>
#include <string>

using namespace std;

class ViewByCategoryController {
public:
    bool open();
    void showList(vector<string>equipmentCategory);
    int getValidInput(int n);
    void getEquipmentCategory(vector<string>&equipmentCategory);
    void showOutStanding(string equipmentCategory, vector<string>equipmentId ,vector<string>roll, vector<string> issueDate, vector<string> returnDate );
    void getOutStandingList(string equipment,vector< string > &equipmentId,vector<string > &roll ,vector<string> &issueDate,vector<string>&returnDate);
    int getAvailableList(string equipment);
    void showAvailableList(int count, string equipmentCategory);
    bool logout();
    bool goBackToViewDetails();
};


#endif //UNTITLED_VIEWBYCATEGORYCONTROLLER_H
