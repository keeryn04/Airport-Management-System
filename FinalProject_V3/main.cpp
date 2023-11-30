#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "main.h"

int main () { 
    Our_Flight f = populate_flight("flight_info.txt");

    int choice = -1;
    display_header();
    
    while (choice != 0) { //Menu with choices for user, calls respective functions with choice
        switch(menu()) {
            case 1: 
                displaySeatMap(f);
                press_enter();
                break;
            case 2:
                displayPassenger(f);
                press_enter();
                break;
            case 3:
                addPassenger(f);
                press_enter();
                break;
            case 4:
                cout << "4 is out of commision rn";
                //f.removePassenger(f);
                press_enter();
                break;
            case 5:
                cout << "5 worked";
                //f.saveData();
                press_enter();
                break;
            case 6:
                cout << "Exiting...";
                choice = 0;
        }
    }

    return 0;
}

Our_Flight populate_flight(const char* filename) {
    Our_Flight f; //Temp instance of flight for storing info
    Our_Airline a; //Temp instance of airline for storing flight

    ifstream in_file(filename, ios::in); //Error output for file opening
    if (in_file.fail()) {
        cerr << "Error Opening File: " << filename << endl;
        throw runtime_error("Failed to open file");
    }
    int index = 0;
    size_t index_flight = 0;
    char s[21];
    int numRows, numSeats, seatRow, pass_id; //numRows and numSeats are for the plane rows and seats
    char seatColumn; //seatColumn and seatRow are for the specific seat of passenger
    string flight_id, fName, lName, phone;
    Our_Passenger passengerInfo;
    Our_Airline airlineInfo;

    in_file >> flight_id >> numRows >> numSeats; //Gets values for the flight info

    f.set_flight_id(flight_id);
    f.set_numRows(numRows);
    f.set_numSeats(numSeats);

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

            passengerInfo.set_Seat(seatRow, seatColumn, 'T', numRows, numSeats);

            f.set_Passenger(passengerInfo, index);

            f.set_Seat_in_map(*passengerInfo.get_Seat());

            a.addFlight(f, index_flight);


            index++;
        } else { //If any error in data detected, it skips that passenger
            cerr << "Invalid seat information for passenger " << pass_id << ". Skipping." << endl;
        }
    } while (!in_file.eof());

    f.set_numPass(index);

    in_file.close();
    return f;
}

void cleanStandardInputStream() { //Cleans cin buffer if called
    int leftover;
    do {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}

void press_enter() { //Waits until enter input from user
    cout << "\n--Press Enter to Continue--" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

void display_header() { //Output for user
    cout << "\n--------------------" << endl;
    cout << "\nVersion 1.0" << endl;
    cout << "Term Project: - Flight Management Program in C++" << endl;
    cout << "Produced By Keeryn Johnson, Mohammed Azmath Khan, Saim Khalid" << endl;
    cout << "Year: 2023" << endl;
    press_enter();
}

int menu() { //Output for user
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

string trim_trailing_spaces(string& s) { //Removes spaces in each value recieved from file
    while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0) {
        s.pop_back();
    }
    return s;
}

void displaySeatMap(Our_Flight& f) { //Use inner loop to create each grid
    cout << "Aircraft Seat Map" << endl;
    cout << "  ";
    for (size_t i = 0; i < f.get_Seatmap()[0].size(); ++i) { 
        cout << static_cast<char>('A' + i) << " "; 
    }
    cout << endl;

    for (size_t i = 0; i < f.get_Seatmap().size(); ++i) { 
        cout << i + 1 << " ";
        for (size_t j = 0; j < f.get_Seatmap()[i].size(); ++j) { 
            char seatStatus = ' ';
            if (f.get_Seatmap()[i][j].get_row() != -1) {
                seatStatus = 'X';
            }
            cout << seatStatus << " ";
        }
        cout << endl;
    }
}

void displayPassenger(Our_Flight& f) {
    int width = 15;


    cout << "Displaying Passengers...\n" << endl;
    cout << "First Name         Last Name         Phone          Row   Seat  ID";
    cout << "\n------------------------------------------------------------------------" << endl;
    for (int i = 0; i < f.get_numPass(); i++) {
        cout << left << setw(width + 4) << f.get_Passenger(i).getfName()
             << setw(width + 3) << f.get_Passenger(i).getlName()
             << setw(width + 1) << f.get_Passenger(i).getPhoneNumber()
             << setw(width - 8) << f.get_Passenger(i).get_Seat()->get_row()
             << setw(width - 10) << f.get_Passenger(i).get_Seat()->get_col()
             << setw(width) << f.get_Passenger(i).get_id() << endl;
        cout << "------------------------------------------------------------------------" << endl;
    }
}


void addPassenger(Our_Flight& f) { 
    Our_Passenger p; //Temp passenger instance to put info into

    int seatRow, pass_id; 
    char seatColumn; 
    string fName, lName, phone;

    cout << "Setting up new passenger..." << endl;
    cout << "Please Enter Passenger Id: "; //Initial input used before loop starts
    cin >> pass_id;
    int i = 0;

    while ((std::cin.fail()) || pass_id < 10000 || pass_id > 99999 || pass_id == f.get_Passenger(i).get_id()) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear(); //Clears error from invalid input
        cleanStandardInputStream(); //Clears buffer of invalid input, then asks for input again
        cout << "Please Enter Passenger Id: ";
        cin >> pass_id;
        for (int i = 0; i < f.get_numPass(); i++) {
            if ((std::cin.fail()) || pass_id < 10000 || pass_id > 99999 || pass_id == f.get_Passenger(i).get_id()) {
                cout << "\Invalid or Repeating value detected. \n";
                std::cin.clear(); //Clears error from invalid input
                cleanStandardInputStream(); //Clears buffer of invalid input, then asks for input again
                cout << "Please Enter Passenger Id: ";
                cin >> pass_id;
            } else {
                return;
            }
        }
    }

    cout << "Please Enter Passenger First Name: ";
    cin >> fName;
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid name." << std::endl;
        std::cin.clear();
        cleanStandardInputStream();
        cout << "Please Enter Passenger First Name: ";
        cin >> fName;
    }

    cout << "Please Enter Passenger Last Name: ";
    cin >> lName;
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid name." << std::endl;
        std::cin.clear();
        cleanStandardInputStream();
        cout << "Please Enter Passenger Last Name: ";
        cin >> lName;
    }

    cout << "Please Enter Passenger Phone Number: ";
    cin >> phone;
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        cleanStandardInputStream();
        cout << "Please Enter Passenger Phone Number: ";
        cin >> phone;
    }

    cout << "Please Enter Desired Row Number: ";
    cin >> seatRow;
    while (std::cin.fail() || seatRow > f.get_numRows() || seatRow <= 0) {
        std::cout << "Invalid input. Please enter a valid seat number." << std::endl;
        std::cin.clear();
        cleanStandardInputStream();
        cout << "Please Enter Desired Row Number: ";
        cin >> seatRow;
    }

    cout << "Please Enter Desired Seat Letter: ";
    cin >> seatColumn;
    // || seatColumn - 'A' > f.get_numSeats() || seatColumn < 'A'
    while (std::cin.fail() || seatColumn - 'A' > f.get_numSeats() || seatColumn < 'A') {
        std::cout << "Invalid input. Please enter a valid seat row." << std::endl;

        std::cin.clear();

        cleanStandardInputStream();

        cout << "Please Enter Desired Seat Letter: ";
        cin >> seatColumn;
    }

    for (int i = 0; i < f.get_numPass(); i++) {
        if (pass_id == f.get_Passenger(i).get_id() || (seatRow == f.get_Passenger(i).get_Seat()->get_row() && seatColumn == f.get_Passenger(i).get_Seat()->get_col()) || phone == f.get_Passenger(i).getPhoneNumber()) {
            cout << "\nRepeat value detected. Exiting...\n";
            return;
        }
    }

    //Sets values into temp passenger and temp seat, then puts that into the flight and adds passenger to total amount
    p.set_id(pass_id);
    p.setfName(fName);
    p.setlName(lName);
    p.setPhoneNumber(phone);
    p.set_Seat(seatRow, seatColumn, 'T', f.get_numRows(), f.get_numSeats());
    f.set_Passenger(p, f.get_numPass());
    f.set_Seat_in_map(*p.get_Seat());
    f.set_numPass(f.get_numPass() + 1);

    cout << "Passenger Created\n";
}

void removePassenger(Our_Airline& a) { //Have to figure out how to delete instances
    int pass_id; 

    cout << "Removing passenger..." << endl;
    cout << "Please Enter Passenger Id: ";
    cin >> pass_id;
    for (int i = 0; i < a.getFlight(i).get_numPass(); i++) { //Checks through each passenger instance
        if (a.getFlight(i).get_Passenger(i).get_id() == pass_id) { //Finds passenger with that pass_id and deletes them
            continue;
        } else {
            cout << "No passenger found with that id. Exiting...";
        }
    } 
    //f.set_numPass(f.get_numPass() - 1); //Removes passenger from flight instance

    cout << "Passenger Deleted";
}