#include <iostream>
using namespace std;

#include "Airline.h"

int main(void) {
    Our_Airline myAirline;

    myAirline.setAirlineName("XYZ Airlines");

    Our_Flight flight1;
    flight1.set_flight_id("WJ1145");
    flight1.set_numRows(30);
    flight1.set_numSeats(10);

    myAirline.addFlight(flight1);

    myAirline.displayFlights();

    myAirline.removeFlight(0);

    myAirline.displayFlights();

    return 0;
}


