#include <iostream>
using namespace std;

#include "main.h"

int main () {
    Our_Flight f = populate_flight("flight.txt");
    std::string id = f.get_flight_id();
    int rows = f.get_numRows();
    int seats = f.get_numSeats();
    Our_Seat seatInfo = f.get_Seat();



    cout << id << " " << rows << " " << seats <<  " " << seatInfo.get_row() << seatInfo.get_col();
    int choice = -1;
    #if 0
    while (choice != 0) {
        switch(menu()) {
            case 1: 
                f.displaySeatMap();
                pressEnter();
                break;
            case 2:
                f.displayPassenger();
                pressEnter();
                break;
            case 3:
                f.addPassenger(f);
                pressEnter();
                break;
            case 4:
                f.removePassenger(f);
                pressEnter();
                break;
            case 5:
                f.saveData();
                pressEnter();
                break;
            case 6:
                choice = 0;
        }
    }
    #endif
    return 0;
}