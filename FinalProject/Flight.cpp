#include <iostream>
using namespace std;

#include "Flight.h"

int main(void) {
    Our_Flight myFlight;

    myFlight.set_flight_id("WJ1145");
    myFlight.set_numRows(30);
    myFlight.set_numSeats(10);

    std::string id = myFlight.get_flight_id();
    int rows = myFlight.get_numRows();
    int seats = myFlight.get_numSeats();

    cout << id << " " << rows << " " << seats;
    return 0;
}