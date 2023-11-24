#ifndef OUR_FLIGHT
#define OUR_FLIGHT

#include <vector>
#include <string>

#include "Seat.h"
#include "Passenger.h"

class Our_Flight {
    public:
        void set_flight_id(std::string flight_id);
        std::string get_flight_id() const;
        
        void set_numRows(int num);
        int get_numRows() const;

        void set_numSeats(int num);
        int get_numSeats() const;

        void set_Seat(Our_Seat seatInfo);
        Our_Seat get_Seat() const;

        void set_Passenger(Our_Passenger passengerInfo);
        Our_Passenger get_Passenger() const;

    private:
        typedef std::vector<std::vector<Our_Seat>> Seatmap;
        typedef std::vector<Our_Passenger> Passengers;
        std::string flight_id;
        int numRows;
        int numSeats;
        int numPassengers;
};

//Setters
void Our_Flight::set_flight_id(std::string flight_id) {
    this->flight_id = flight_id;
}

void Our_Flight::set_numRows(int num) {
    this->numRows = num;
}

void Our_Flight::set_numSeats(int num) {
    this->numSeats = num;
}

void Our_Flight::set_Seat(Our_Seat seatInfo) {
    Seatmap seatmap;
    
    seatmap.resize(numRows);

    for (auto& row : seatmap) {
        row.resize(numSeats);
    }

    seatmap[seatInfo.get_row()][seatInfo.get_col()] = seatInfo;
}

void set_Passenger(Our_Passenger passengerInfo) {

}



//Getters
std::string Our_Flight::get_flight_id() const {
    return flight_id;
}

int Our_Flight::get_numRows() const {
    return numRows;
}

int Our_Flight::get_numSeats() const {
    return numSeats;
}

Our_Seat Our_Flight::get_Seat() const {

}

#endif