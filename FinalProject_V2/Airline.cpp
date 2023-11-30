#include <iostream>
using namespace std;

#include "main.h"

//Default Constructor
Our_Airline::Our_Airline() {
    airlineName = "Default Airline";
}

//Setters
void Our_Airline::setAirlineName(std::string name) {
    airlineName = name;
}

void Our_Airline::addFlight(const Our_Flight& flight) {
    flights.push_back(flight);
}

void Our_Airline::removeFlight(size_t index) {
    if (index >= 0 && index < flights.size()) {
        flights.erase(flights.begin() + index);
    } else {
        std::cout << "Invalid flight index for removal" << std::endl;
    }
}

//Getters
std::string Our_Airline::getAirlineName() const {
    return airlineName;
}

void Our_Airline::displayFlights() {
    std::cout << "Flights for " << airlineName << std::endl;
    for (size_t i = 0; i < flights.size(); ++i) {
        std::cout << "Flight " << i + 1 << ": " << flights[i].get_flight_id() << std::endl;
    }
}


