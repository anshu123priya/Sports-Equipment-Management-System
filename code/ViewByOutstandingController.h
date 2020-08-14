#ifndef UNTITLED_VIEWBYOUTSTANDINGCONTROLLER_H
#define UNTITLED_VIEWBYOUTSTANDINGCONTROLLER_H

#include <string>
#include <vector>

using namespace std;

class ViewByOutstandingController {
public:
    bool open();
    void getOutstandingList(vector<string> &equipmentCategory, vector<string> &equipmentId, vector<string> &roll, vector<string> &issueDate, vector<string> &returnDate);
    void showOutStandingList(vector<string> equipmentCategory, vector<string> equimentId, vector<string> roll, vector<string> issueDate, vector<string> returnDate);
    bool  logout();
    bool goBackToViewDetails();
    int getValidInput();
};


#endif //UNTITLED_VIEWBYOUTSTANDINGCONTROLLER_H
