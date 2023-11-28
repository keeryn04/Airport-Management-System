#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "main.h"

int main () {
    Our_Flight f = populate_flight("flight_info.txt");
    #if 0
    string id = f.get_flight_id();
    int rows = f.get_numRows();
    int seats = f.get_numSeats();
    Our_Seat seat = f.get_Seat(6,'A');
    Our_Passenger pass = f.get_Passenger(0);

    //cout << id << " " << rows << " " << seats << " " << seat.get_row() << " " << seat.get_col() << " " << pass.getfName();
    #endif
    int choice = -1;
    display_header();
    
    #if 1
    while (choice != 0) {
        switch(menu()) {
            case 1: 
                cout << "1 worked";
                //f.displaySeatMap();
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
    #endif
    return 0;
}

#if 1
Our_Flight populate_flight(const char* filename) {
    Our_Flight f;

    ifstream in_file(filename, ios::in);
    if (in_file.fail()) {
        cerr << "Error Opening File: " << filename << endl;
        throw runtime_error("Failed to open file");
    }

    int numRows, numSeats, rowNum, pass_id;
    char colNum;
    string flight_id, fName, lName, phone;
    Our_Seat seatInfo;
    Our_Passenger passengerInfo;

    in_file >> flight_id >> numRows >> numSeats;

    f.set_flight_id(flight_id);
    f.set_numRows(numRows);
    f.set_numSeats(numSeats);
    
    int index = 0;
    string line;
    while (getline(in_file, line, '\n') || EOF == 1) { //Loop for getting passenger info
        //Gets strings
        std::getline(in_file, fName, '\t');
        std::getline(in_file, lName, '\t');
        std::getline(in_file, phone, '\t');

        in_file >> rowNum >> colNum >> pass_id; //Gets values after strings
        
        cout << fName << " " << lName << " " << phone << " " << rowNum << " " << colNum << " " << pass_id;

        passengerInfo.setfName(fName);
        passengerInfo.setlName(lName);
        passengerInfo.setPhoneNumber(phone);
        passengerInfo.set_id(pass_id);
        f.set_Passenger(passengerInfo, index);

        seatInfo.set_col(rowNum);
        seatInfo.set_col(colNum);
        seatInfo.set_status('T');
        
        if (rowNum >= 0 && rowNum < numRows && colNum >= 'A' && colNum < 'A' + numSeats) { //Sets each seat
            f.set_Seat(seatInfo);
        } else {
            break;
        }
        index++; //Tracks number of passengers
    }

    in_file.close();
    return f;
}
#endif

#if 0
Our_Flight populate_flight(const char* filename) {
    Our_Flight f;
    //Initialize variables for saving
    char s[21];
    int index = 0; //Used to store amount of passengers

    int numRows, numSeats, rowNum, pass_id;
    char colNum;
    string flight_id, fName, lName, phone;
    Our_Seat seatInfo;
    Our_Passenger passengerInfo;

    ifstream in_file(filename, ios::in); //Checks if file is open correctly
    if (in_file.fail()) {
        cerr << "Error Opening File: " << filename << endl;
        throw runtime_error("Failed to open file");
    }

    do { //Saves data from file to variables
        in_file.get(s, 21, '\n');
        if (in_file.eof()) {
            break;
        }
        fName = s;
        fName = trim_trailing_whitespace(fName);
        lName = s;
        lName = trim_trailing_whitespace(lName);
        phone = s;
        phone = trim_trailing_whitespace(phone);
        in_file >> rowNum >> colNum >> pass_id;

        passengerInfo.setfName(fName);
        passengerInfo.setlName(lName);
        passengerInfo.setPhoneNumber(phone);
        passengerInfo.set_id(pass_id);

        seatInfo.set_row(rowNum);
        seatInfo.set_col(colNum);
        seatInfo.set_status('T');

        f.set_Passenger(passengerInfo, index);
        f.set_Seat(seatInfo);
    } while (in_file.eof() != 1);

    index++;
    in_file.close();
    return f;
}
#endif


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