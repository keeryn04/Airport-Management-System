// Airline.cpp
#include "Airline.h"

Our_Airline::Our_Airline() {
    // Constructor implementation if needed
}

void Our_Airline::addFlight(const Our_Flight& flight) {
    flights.push_back(flight);
}

Our_Flight Our_Airline::getFlight(const std::string& flight_id) const {
    for (const auto& flight : flights) {
        if (flight.get_flight_id() == flight_id) {
            return flight;
        }
    }
    // If flight_id is not found, return an empty flight
    return Our_Flight();
}

