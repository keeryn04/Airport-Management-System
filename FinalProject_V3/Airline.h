#ifndef OUR_AIRLINE
#define OUR_AIRLINE

#include "Flight.h"

class Our_Airline {
public:
    Our_Airline();

    void setAirlineName(std::string name);
    std::string getAirlineName() const;

    void addFlight(const Our_Flight& flightInfo, size_t &flight_index);
    void removeFlight(size_t index);

    Our_Flight getFlight(size_t flight_index) const;

    void displayFlights();

private:
    std::string airlineName;
    std::vector<Our_Flight> flights;
};


#endif