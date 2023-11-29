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

        void displaySeatMap();


    private:
        vector<vector<Our_Seat>> Seatmap;
        vector<Our_Passenger> Passengers;
        string flight_id;
        int numRows;
        int numSeats;
};

//Default Constructor, resizes vector accordingly
Our_Flight::Our_Flight() {
    Seatmap.resize(numRows, vector<Our_Seat>(numSeats));
}

//Setters
void Our_Flight::set_flight_id(string flight_id) {
    this->flight_id = flight_id;
}

void Our_Flight::set_numRows(int num) {
    this->numRows = num;
}

void Our_Flight::set_numSeats(int num) {
    this->numSeats = num;
}

void Our_Flight::set_Seat(const Our_Seat& seatInfo) { //Sets seat information into the each seat class, allowing access later on
    if (seatInfo.get_row() >= 0 && seatInfo.get_row() < numRows && seatInfo.get_col() >= 'A' && seatInfo.get_col() < 'A' + numSeats) {
        Seatmap[seatInfo.get_row()][seatInfo.get_col() - 'A'] = seatInfo; //Checks if valid seat, then creates spot in seatmap with copy of that info
    } else {
        std::cout << "Invalid Seat row or column created" << endl;
    }
}

void Our_Flight::set_Passenger(Our_Passenger& passengerInfo, int passNum) { //Sets info into each passenger based on index, and resizes if required
    if (passNum >= 0) {
        if (passNum >= Passengers.size()) {
            Passengers.resize(passNum + 1);
        }
        Passengers[passNum] = passengerInfo; //Checks if valid passenger, then creates new passenger instance with copy of that info
    } else {
        std::cout << "Invalid passenger index created" << endl;
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

Our_Seat Our_Flight::get_Seat(int row, char col) const { //Returns class instance of Our_Seat to access info inside specific row or column
    if (row >= 0 && row < numRows && col >= 'A' && col < 'A' + numSeats) {
        return Seatmap[row][col - 'A'];
    } else {
        std::cout << "Invalid seat index retrieved" << endl;
        return Our_Seat();
    }
}

Our_Passenger Our_Flight::get_Passenger(int index) const { //Returns class instance of Our_Passenger if valid to acess info for each passenger
    if (Passengers.empty() != 1 && index >= 0 && index < Passengers.size()) {
        return Passengers[index];
    } else {
        std::cout << "Invalid passenger index retrieved" << endl;
        return Our_Passenger();
    }
}

void Our_Flight::displaySeatMap() {
    cout << "Aircraft Seat Map" << endl;
    cout << "  ";
    for (int i = 0; i < Seatmap[0].size(); ++i) {
        cout << static_cast<char>('A' + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < Seatmap.size(); ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < Seatmap[i].size(); ++j) {
            char seatStatus = ' ';
            if (Seatmap[i][j].get_row() != -1) {
                seatStatus = 'X';
            }
            cout << seatStatus << " ";
        }
        cout << endl;
    }
}

#endif