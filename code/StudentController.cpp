#include <bits/stdc++.h>

#include "StudentController.h"
#include "StudentLoginController.h"
//#include "StudentLoginController.cpp"

using namespace std;

bool StudentController::open() {

    StudentLoginController myStudentLoginController;
    return myStudentLoginController.open(this->student);

}
