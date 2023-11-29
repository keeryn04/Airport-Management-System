#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "main.h"

int main () {
    Our_Flight f = populate_flight("flight_info.txt");
    //cd c:/Users/keery/ENSF337/FinalProject

    #if 1
    string id = f.get_flight_id();
    int rows = f.get_numRows();
    int seats = f.get_numSeats();
    Our_Seat seat = f.get_Seat(6,'D');
    Our_Passenger pass = f.get_Passenger(1);

    cout << id << " " << rows << " " << seats << " " << seat.get_row() << " " << seat.get_col() << " " << pass.getfName() << " " << pass.get_id();
    #endif

    int choice = -1;
    display_header();
    
    while (choice != 0) {
        switch(menu()) {
            case 1: 
                cout << "1 worked";
                f.displaySeatMap();
                pressEnter();
                break;
            case 2:
                cout << "2 worked";
                //f.displayPassenger();
                pressEnter();
                break;
            case 3:
                cout << "3 worked";
                //f.addPassenger(f);
                pressEnter();
                break;
            case 4:
                cout << "4 worked";
                //f.removePassenger(f);
                pressEnter();
                break;
            case 5:
                cout << "5 worked";
                //f.saveData();
                pressEnter();
                break;
            case 6:
                choice = 0;
        }
    }

    return 0;
}

Our_Flight populate_flight(const char* filename) {
    Our_Flight f;

    ifstream in_file(filename, ios::in);
    if (in_file.fail()) {
        cerr << "Error Opening File: " << filename << endl;
        throw runtime_error("Failed to open file");
    }
    int index = 0;
    char s[21];
    int numRows, numSeats, seatRow, pass_id; //numRows and numSeats are for the plane rows and seats
    char seatColumn; //seatColumn and seatRow are for the specific seat of passenger
    string flight_id, fName, lName, phone;
    Our_Seat seatInfo;
    Our_Passenger passengerInfo;

    in_file >> flight_id >> numRows >> numSeats; //Gets values for the plane

    f.set_flight_id(flight_id);
    f.set_numRows(numRows);
    f.set_numSeats(numSeats);

    #if 1
    do { //Saves data from file to variables
        in_file.get(s, 21, '\0');
        if (in_file.eof()) break;
        fName = s;
        trim_trailing_spaces(fName);

        in_file.get(s, 21, '\0');
        if (in_file.eof()) break;
        lName = s;
        trim_trailing_spaces(lName);

        in_file.get(s, 21, '\0');
        if (in_file.eof()) break;
        phone = s;
        trim_trailing_spaces(phone);

        in_file >> seatRow >> seatColumn >> pass_id;

        if (seatRow >= 0 && seatRow < numRows && seatColumn >= 'A' && seatColumn < 'A' + numSeats) { //Checks that seat is valid on this flight, and sets info up accordingly
            passengerInfo.setfName(fName);
            passengerInfo.setlName(lName);
            passengerInfo.setPhoneNumber(phone);
            passengerInfo.set_id(pass_id);

            seatInfo.set_row(seatRow);
            seatInfo.set_col(seatColumn);
            seatInfo.set_status('T');

            f.set_Passenger(passengerInfo, index);
            f.set_Seat(seatInfo);
            index++;

        } else { //If any error in data detected, it skips that passenger
            cerr << "Invalid seat information for passenger " << pass_id << ". Skipping." << endl;
        }
    } while (!in_file.eof());

    in_file.close();
    return f;

    #endif
}

void cleanStandardInputStream() {
    int leftover;
    do {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}

void pressEnter() {
    cout << "\n--Press Enter to Continue--" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

void display_header() {
    cout << "\n--------------------" << endl;
    cout << "\nVersion 1.0" << endl;
    cout << "Term Project: - Flight Management Program in C++" << endl;
    cout << "Produced By Keeryn Johnson, Mohammed Azmath Khan, " << endl;
    cout << "Year: 2023" << endl;
    pressEnter();
}

int menu() {
    int choice = -1;
    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passenger Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove Existing Passenger" << endl;
    cout << "5. Save Data" << endl;
    cout << "6. Quit" << endl;
    cout << endl;
    cout << "Enter number here: ";
    cin >> choice;
    return choice;
}

string trim_trailing_spaces(string& s) {
    while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0) {
        s.pop_back();
    }
    return s;
}
