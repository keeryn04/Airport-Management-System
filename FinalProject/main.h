#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"

#if 1
Our_Flight populate_flight(const char* filename) {
    Our_Flight f;

    ifstream in_file(filename, ios::in);
    if (in_file.fail()) {
        cout << "Error Opening File, Exiting..." << endl;
        exit(1);
    }

    int numRows, numSeats;
    string flight_id;
    Our_Seat seatInfo;
    Our_Passenger passengerInfo;

    in_file >> flight_id >> numRows >> numSeats; //Gets the info from the file for the flight
    //Need a for loop that gets each passenger, and saves amount for the vector later on
    
    f.set_flight_id(flight_id);
    f.set_numRows(numRows);
    f.set_numSeats(numSeats);
    f.set_Seat(seatInfo);
    #if 0
    f.set_Passenger(passengerInfo);
    #endif
    in_file.close();
    return f;
}
#endif

void pressEnter() {
    cout << "\n--Press Enter to Continue--" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

int menu() {
    int choice = -1;
    cout << "Version 1.0" << endl;
    cout << "Term Project: - Flight Management Program in C++" << endl;
    cout << "Produced By Keeryn Johnson, Mohammed Azmath Khan, " << endl;
    cout << "Year: 2023" << endl;
    pressEnter();

    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passenger Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove Existing Passenger" << endl;
    cout << "5. Save Data" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;
    return choice;
}


