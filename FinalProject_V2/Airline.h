#ifndef OUR_AIRLINE
#define OUR_AIRLINE

#include "Flight.h"

class Our_Airline {
public:
    Our_Airline();

    void setAirlineName(std::string name);
    std::string getAirlineName() const;

    void addFlight(const Our_Flight& flight);
    void removeFlight(size_t index);

    void displayFlights();

private:
    std::string airlineName;
    std::vector<Our_Flight> flights;
};


#endif
