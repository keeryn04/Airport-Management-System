#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "main.h"

int main () { 
    Our_Airline a = populate_flight("flight_info.txt");

    int choice = -1;
    display_header();
    
    while (choice != 0) { //Menu with choices for user, calls respective functions with choice
        switch(menu()) {
            case 1: 
                displaySeatMap(a);
                press_enter();
                break;
            case 2:
                displayPassenger(a);
                press_enter();
                break;
            case 3:
                addPassenger(a);
                press_enter();
                break;
            case 4:
                std::cout << "4 is out of commision rn";
                //f.removePassenger(f);
                press_enter();
                break;
            case 5:
                std::cout << "5 worked";
                //f.saveData();
                press_enter();
                break;
            case 6:
                std::cout << "Exiting...";
                choice = 0;
        }
    }

    return 0;
}

Our_Airline populate_flight(const char* filename) {
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

            index++;
        } else { //If any error in data detected, it skips that passenger
            cerr << "Invalid seat information for passenger " << pass_id << ". Skipping." << endl;
        }
    } while (!in_file.eof());

    f.set_numPass(index);
    a.addFlight(f, index_flight);
    index_flight++;

    in_file.close();
    return a;
}

void cleanStandardInputStream() { //Cleans std::cin buffer if called
    int leftover;
    do {
        leftover = std::cin.get();
    } while (leftover != '\n' && leftover != EOF);
}

void press_enter() { //Waits until enter input from user
    std::cout << "\n--Press Enter to Continue--" << endl;
    std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

void display_header() { //Output for user
    std::cout << "\n--------------------" << endl;
    std::cout << "\nVersion 1.0" << endl;
    std::cout << "Term Project: - Flight Management Program in C++" << endl;
    std::cout << "Produced By Keeryn Johnson, Mohammed Azmath Khan, Saim Khalid" << endl;
    std::cout << "Year: 2023" << endl;
    press_enter();
}

int menu() { //Output for user
    int choice = -1;
    std::cout << "Please select one of the following options:" << endl;
    std::cout << "1. Display Flight Seat Map" << endl;
    std::cout << "2. Display Passenger Information" << endl;
    std::cout << "3. Add a New Passenger" << endl;
    std::cout << "4. Remove Existing Passenger" << endl;
    std::cout << "5. Save Data" << endl;
    std::cout << "6. Quit" << endl;
    std::cout << endl;
    std::cout << "Enter number here: ";
    std::cin >> choice;
    return choice;
}

string trim_trailing_spaces(string& s) { //Removes spaces in each value recieved from file
    while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0) {
        s.pop_back();
    }
    return s;
}

void displaySeatMap(Our_Airline& a) { //Use inner loop to create each grid
    std::cout << "Aircraft Seat Map" << endl;
    std::cout << "  ";
    for (size_t j = 0; j < a.getFlightVector().size(); j++) {
        for (size_t i = 0; i < a.getFlight(j).get_Seatmap()[0].size(); ++i) { 
            std::cout << static_cast<char>('A' + i) << " "; 
        }
        std::cout << endl;

        for (size_t i = 0; i < a.getFlight(j).get_Seatmap().size(); ++i) { 
            std::cout << i + 1 << " ";
            for (size_t j = 0; j < a.getFlight(j).get_Seatmap()[i].size(); ++j) { 
                char seatStatus = ' ';
                if (a.getFlight(j).get_Seatmap()[i][j].get_row() != -1) {
                    seatStatus = 'X';
                }
                std::cout << seatStatus << " ";
            }
            std::cout << endl;
        }
    }
}

void displayPassenger(Our_Airline& a) {
    int width = 15;

    std::cout << "Displaying Passengers...\n" << endl;
    std::cout << "First Name         Last Name         Phone          Row   Seat  ID";
    std::cout << "\n------------------------------------------------------------------------" << endl;
    for (size_t j = 0; j < a.getFlightVector().size(); j++) {
        for (int i = 0; i < a.getFlight(j).get_numPass(); i++) {
            std::cout << left << setw(width + 4) << a.getFlight(j).get_Passenger(i).getfName()
                << setw(width + 3) << a.getFlight(j).get_Passenger(i).getlName()
                << setw(width + 1) << a.getFlight(j).get_Passenger(i).getPhoneNumber()
                << setw(width - 8) << a.getFlight(j).get_Passenger(i).get_Seat()->get_row()
                << setw(width - 10) << a.getFlight(j).get_Passenger(i).get_Seat()->get_col()
                << setw(width) << a.getFlight(j).get_Passenger(i).get_id() << endl;
            std::cout << "------------------------------------------------------------------------" << endl;
        }
    }
}

void addPassenger(Our_Airline& a) { 
    Our_Passenger p; //Temp passenger instance to put info into

    int seatRow, pass_id; 
    char seatColumn; 
    string fName, lName, phone;

    std::cout << "Setting up new passenger..." << endl;
    std::cout << "Please Enter Passenger Id: "; //Initial input used before loop starts
    std::cin >> pass_id;
    for (size_t j = 0; j < a.getFlightVector().size(); j++) { //iteraters through flights
        for (int i = 0; i < a.getFlight(j).get_numPass(); i++) { //iterates through passengers on flight
            while (std::cin.fail() || pass_id < 10000 || pass_id > 99999 || pass_id == a.getFlight(j).get_Passenger(i).get_id()) {   
                std::cout << "Invalid or Repeating input. Please enter a valid ID." << std::endl;
                std::cin.clear();
                cleanStandardInputStream();
                std::cout << "Please Enter Passenger ID: ";
                std::cin >> pass_id;
            }
        }

        std::cout << "Please Enter Passenger First Name: ";
        std::cin >> fName;
        while (std::cin.fail()) {   
            std::cout << "Invalid input. Please enter a valid name." << std::endl;
            std::cin.clear();
            cleanStandardInputStream();
            std::cout << "Please Enter Passenger First Name: ";
            std::cin >> fName;
        }

        std::cout << "Please Enter Passenger Last Name: ";
        std::cin >> lName;
        while (std::cin.fail()) {   
            std::cout << "Invalid input. Please enter a valid name." << std::endl;
            std::cin.clear();
            cleanStandardInputStream();
            std::cout << "Please Enter Passenger Last Name: ";
            std::cin >> lName;
        }

        std::cout << "Please Enter Passenger Phone Number: ";
        std::cin >> phone;
        while (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            cleanStandardInputStream();
            std::cout << "Please Enter Passenger Phone Number: ";
            std::cin >> phone;
        }

        std::cout << "Please Enter Desired Row Number: ";
        std::cin >> seatRow;
        std::cout << "Please Enter Desired Seat Letter: ";
        std::cin >> seatColumn;
        for (int i = 0; i < a.getFlight(j).get_numPass(); i++) {
            while (std::cin.fail() || seatRow > a.getFlight(j).get_numRows() || seatRow <= 0 || (a.getFlight(j).get_Passenger(i).get_Seat()->get_row() == seatRow && a.getFlight(j).get_Passenger(i).get_Seat()->get_col() == seatColumn)) {
                std::cout << "Invalid input. Please enter a valid seat number." << endl;
                std::cin.clear();
                cleanStandardInputStream();
                std::cout << "Please Enter Desired Row Number: ";
                std::cin >> seatRow;
                std::cout << "Please Enter Desired Seat Letter: ";
                std::cin >> seatColumn;
            }
        }

        p.set_id(pass_id);
        p.setfName(fName);
        p.setlName(lName);
        p.setPhoneNumber(phone);
        p.set_Seat(seatRow, seatColumn, 'T', a.getFlight(j).get_numRows(), a.getFlight(j).get_numSeats());

        int updatedPassengerCount = a.getFlight(j).get_numPass();  
        a.getFlight(j).set_Passenger(p, updatedPassengerCount);
        a.getFlight(j).set_numPass(a.getFlight(j).get_numPass() + 1);
        a.getFlight(j).set_Seat_in_map(*p.get_Seat());
    }
}

void removePassenger(Our_Airline& a) { //Have to figure out how to delete instances
    int pass_id; 

    std::cout << "Removing passenger..." << endl;
    std::cout << "Please Enter Passenger Id: ";
    std::cin >> pass_id;
    for (size_t j = 0; j < a.getFlightVector().size(); j++) {
        for (int i = 0; i < a.getFlight(j).get_numPass(); i++) { //Checks through each passenger instance
            if (a.getFlight(i).get_Passenger(i).get_id() == pass_id) { //Finds passenger with that pass_id and deletes them
                continue;
            } else {
                std::cout << "No passenger found with that id. Exiting...";
            }
        } 
    }
    //f.set_numPass(f.get_numPass() - 1); //Removes passenger from flight instance

    std::cout << "Passenger Deleted";
}