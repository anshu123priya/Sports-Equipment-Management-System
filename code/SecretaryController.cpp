#include "SecretaryController.h"
#include "SecretaryLoginController.h"
//#include "SecretaryLoginController.cpp"

using namespace std;

bool SecretaryController::open() {

    SecretaryLoginController mySecretaryLoginController;
    return mySecretaryLoginController.open(this->secretary);

}
