// Airline.h
#ifndef OUR_AIRLINE
#define OUR_AIRLINE

#include <vector>
#include <string>
#include "Flight.h"

class Our_Airline {
public:
    Our_Airline();

    void addFlight(const Our_Flight& flight);
    Our_Flight getFlight(const std::string& flight_id) const;

private:
    std::vector<Our_Flight> flights;
};

#endif

