#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H


#include<string>

using namespace  std;

class Student {
    string  name;
    string roll;
    string userName;
    double dues;
public:
    bool matchDetailsStudent(string,string);
    string getName();
    string getRoll();
    string getUserName();
    double getDues();
    void clearDues(double val);
    bool matchDetailsSecretary(string userName,string password);
    void addDues(double due);
    bool getDetailsByRoll(string roll);
};


#endif //UNTITLED_STUDENT_H
