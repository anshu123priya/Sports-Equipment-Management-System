#ifndef UNTITLED_OUTSTANDINGEQUIPMENTS_H
#define UNTITLED_OUTSTANDINGEQUIPMENTS_H

#include<string>
#include<vector>
#include "Student.h"

using namespace std;

class OutstandingEquipments {
public:
    bool removeOutStanding(string equipments,Student student);
    void addToOutStandingData(vector<string> equipments,vector<string> equipmentId,Student student,vector<string> date);
    void getListOfOtstanding(string & equipment,vector<string> & equipmentId,vector<string> & roll,vector<string> & issueDate,vector<string> & returnDate);
    void removeFromOutStanding(vector<string> equipmentId);
    void getCompleteList(vector<string> &equipments,vector<string> &equipmentId,vector<string> &roll,vector<string> &issueDate,vector<string> &returnDate);
    string getTodayDate();
    int issuedByStudent(Student student);
    int to_integer(string s);
    string toString(int x);
    string returnDate(string date);
    string getId(string equipmentCategory, Student student);
    int additionalDays(string equipmentId);
};


#endif //UNTITLED_OUTSTANDINGEQUIPMENTS_H

