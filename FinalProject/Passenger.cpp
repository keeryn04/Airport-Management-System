#include <iostream>
using namespace std;

#include "Passenger.h"

int main(void) {
    Our_Passenger myPassenger;

    myPassenger.setFirstName("John");
    myPassenger.setLastName("Smith");
    myPassenger.setPhoneNumber("403-111-2222");

    std::string Fname = myPassenger.getFirstName();
    std::string Lname = myPassenger.getLastName();
    std::string Pnumber = myPassenger.getPhoneNumber();

    cout << Fname << " " << Lname << " " << Pnumber;
    return 0;
}