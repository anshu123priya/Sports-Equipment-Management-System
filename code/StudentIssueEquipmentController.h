#ifndef UNTITLED_STUDENTISSUEEQUIPMENTCONTROLLER_H
#define UNTITLED_STUDENTISSUEEQUIPMENTCONTROLLER_H

#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class StudentIssueEquipmentController {
public:
    bool open(Student student);
    bool checkDue(Student student);
    void showMessage(string show);
    int getValidInput(int n);
    bool canIssue(Student student);
    void showEquipmentList(vector<string>equipmentCategory);
    void showFinalEquipmentsList(vector<string> equipmentCategory);
    void getAvailableEquipments(vector<string>&equipmentCategory, Student student);
    void getEquipmentData(vector<string>&equipmentCategory, vector<string> &equipmentId, vector<string> &issueDate);
    bool guardVerification();
    void changeEquipmentData(vector<string> equipmentCategory, vector<string> equipmentId, Student student, vector<string>Date);
    bool logout();
    bool backToHomepage();
};


#endif //UNTITLED_STUDENTISSUEEQUIPMENTCONTROLLER_H
