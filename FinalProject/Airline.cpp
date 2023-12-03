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

void Our_Airline::setFlight(const Our_Flight& flightInfo, size_t flight_index) {
    if (flight_index >= 0) {
        if (flights.size() <= flight_index) {
            flights.resize(flight_index + 1);
        }
        flights[flight_index] = flightInfo;
        flight_index++;

    } else {
        std::cout << "Invalid flight index created" << endl;
    }
}

void Our_Airline::removeFlight(size_t index) { //Deletes flight if that flight index is found
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

void Our_Airline::displayFlights() { //Shows all flights in airline
    std::cout << "Flights for " << airlineName << std::endl;
    for (size_t i = 0; i < flights.size(); ++i) {
        std::cout << "Flight " << i + 1 << ": " << flights[i].get_flight_id() << std::endl;
    }
}

Our_Flight& Our_Airline::getFlight(size_t flight_index) {
    if (flights.empty() != 1 && flight_index >= 0 && flight_index < flights.size()) {
        return flights[flight_index];
    } else {
        std::cout << "Invalid passenger index retrieved" << std::endl;
        throw std::out_of_range("Invalid flight index");
    }
}


vector<Our_Flight> Our_Airline::getFlightVector() const { //Returns entire flight vector if needed to be accessed
    return flights;
}





