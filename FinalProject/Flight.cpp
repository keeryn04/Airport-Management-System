#include <iostream>
#include <vector>
using namespace std;

#include "main.h"

//Default Constructor, resizes vector accordingly
Our_Flight::Our_Flight() {
    int numRows = 1;
    int numSeats = 1;
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

void Our_Flight::set_numPass(int num) {
    this->numPass = num;
}

void Our_Flight::set_Seat_in_map(const Our_Seat& seatInfo) { //Sets seat information into each seat on seatmap, allowing access later on
    Seatmap.resize(numRows, vector<Our_Seat>(numSeats)); //Extra check, resizes Seatmap vector for setting value (Should be done in seatmap initialization)
    if (seatInfo.get_row() >= 0 && seatInfo.get_row() < numRows && seatInfo.get_col() >= 'A' && seatInfo.get_col() < 'A' + numSeats) {
        Seatmap[seatInfo.get_row()][seatInfo.get_col() - 'A'] = seatInfo; //Checks if valid seat, then creates spot in seatmap with copy of that info
    } else {
        std::cout << "Invalid Seat row or column created" << endl;
    }
}

void Our_Flight::set_Passenger(const Our_Passenger& passengerInfo, size_t passNum) {
    if (passNum >= Passengers.size()) {
        Passengers.resize(passNum + 1);
    }

    Passengers[passNum] = passengerInfo;
    numPass = Passengers.size();  // Update passenger count after adding the passenger
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


int Our_Flight::get_numPass() const {
    return numPass;
}

Our_Seat Our_Flight::get_Seat_in_map(int row, char col) const { //Returns class instance of Our_Seat to access info inside specific row or column
    if (row >= 0 && row < numRows && col >= 'A' && col < 'A' + numSeats) {
        return Seatmap[row][col - 'A'];
    } else {
        std::cout << "Invalid seat index retrieved" << endl;
        return Our_Seat();
    }
}

Our_Passenger Our_Flight::get_Passenger(size_t index) const { //Returns class instance of Our_Passenger if valid to access info for each passenger
    if (Passengers.empty() != 1 && index >= 0 && index < Passengers.size()) {
        return Passengers[index];
    } else {
        std::cout << "Invalid passenger index retrieved" << endl;
        return Our_Passenger();
    }
}

vector<vector<Our_Seat>> Our_Flight::get_Seatmap() const { //Returns entire seatmap if needed to be accessed
    return Seatmap;
}

//Member functions
void Our_Flight::removePassenger(size_t pass_index) {
    if (pass_index >= 0 && pass_index < Passengers.size()) {
        Our_Seat removedSeat = *(Passengers[pass_index].get_Seat()); //Gets seat info for seatmap removal

        Seatmap[removedSeat.get_row()][removedSeat.get_col() - 'A'].set_status('O'); //Removes seat from seatmap

        Passengers.erase(Passengers.begin() + pass_index); //Removes passenger

        numPass = Passengers.size(); 
    } else {
        std::cout << "Invalid passenger index for removal" << std::endl;
    }
}
