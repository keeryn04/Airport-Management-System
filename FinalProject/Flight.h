#ifndef OUR_FLIGHT
#define OUR_FLIGHT

#include <vector>
#include <string>

#include "Seat.h"
#include "Passenger.h"

class Our_Flight {
    public:
        Our_Flight();

        void set_flight_id(std::string flight_id);
        std::string get_flight_id() const;
        
        void set_numRows(int num);
        int get_numRows() const;

        void set_numSeats(int num);
        int get_numSeats() const;

        void set_Seat(const Our_Seat& seatInfo);
        Our_Seat get_Seat(int row, char col) const;

        void set_Passenger(Our_Passenger& passengerInfo, int passNum);
        Our_Passenger get_Passenger(int index) const;

    private:
        vector<vector<Our_Seat>> Seatmap;
        vector<Our_Passenger> Passengers;
        string flight_id;
        int numRows;
        int numSeats;
};

Our_Flight::Our_Flight() {
    Seatmap.resize(numRows, vector<Our_Seat>(numSeats));
}

//Setters
void Our_Flight::set_flight_id(string flight_id) {
    this->flight_id = flight_id;
    cout << "Flight ID set to: " << flight_id << std::endl;

}

void Our_Flight::set_numRows(int num) {
    this->numRows = num;
    cout << "numRows set to: " << num << std::endl;

}

void Our_Flight::set_numSeats(int num) {
    this->numSeats = num;
    cout << "numSeats set to: " << num << std::endl;
}

//Issues with setters, file is properly read and getters are grabbing correct default values, but setters aren't initializing the values the getters should be getting

void Our_Flight::set_Seat(const Our_Seat& seatInfo) {
    if (seatInfo.get_row() >= 0 && seatInfo.get_row() < numRows && seatInfo.get_col() >= 'A' && seatInfo.get_col() < 'A' + numSeats) {
        Seatmap[seatInfo.get_row()][seatInfo.get_col() - 'A'] = seatInfo;
        cout << "Row Number set to: " << seatInfo.get_row() << std::endl;
        cout << "Seat Number set to: " << seatInfo.get_col() << std::endl;
        cout << "Status set to: " << seatInfo.get_status() << std::endl;
    } else {
        std::cout << "Invalid Seat row or column Created" << endl;
    }
}

void Our_Flight::set_Passenger(Our_Passenger& passengerInfo, int passNum) {
    if (passNum >= 0) {
        if (passNum >= Passengers.size()) {
            Passengers.resize(passNum + 1);
        }
        Passengers[passNum] = passengerInfo;
        cout << endl << "fName set to: " << Passengers[passNum].getfName() << std::endl;
        cout << "lName set to: " << Passengers[passNum].getlName() << std::endl;
        cout << "Phone set to: " << Passengers[passNum].getPhoneNumber() << std::endl;
        cout << "ID set to: " << Passengers[passNum].get_id() << std::endl;
    } else {
        std::cout << "Invalid passenger index Created" << endl;
    }
}


//Getters
string Our_Flight::get_flight_id() const {
    return flight_id;
}

int Our_Flight::get_numRows() const {
    return numRows;
}

int Our_Flight::get_numSeats() const {
    return numSeats;
}

Our_Seat Our_Flight::get_Seat(int row, char col) const {
    cout << endl << "Row: " << row << ", Seat: " << col << std::endl;
    if (row >= 0 && row < numRows && col >= 'A' && col < 'A' + numSeats) {
        return Seatmap[row][col - 'A'];
    } else {
        std::cout << "Invalid seat index Retrieved" << endl;
        return Our_Seat();
    }
}

Our_Passenger Our_Flight::get_Passenger(int index) const {
    cout << "Index: " << index << ", Vector Size: " << Passengers.size() << std::endl;
    if (Passengers.empty() != 1 && index >= 0 && index < Passengers.size()) {
        return Passengers[index];
    } else {
        std::cout << "Invalid passenger index Retrieved" << endl;
        return Our_Passenger();
    }
}




#endif