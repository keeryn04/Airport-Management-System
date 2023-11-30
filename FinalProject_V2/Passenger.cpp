#include <iostream>
using namespace std;

#include "main.h"

//Default Constructor
Our_Passenger::Our_Passenger() {
    seat = new Our_Seat;
    id = 0;
    phoneNumber = "911";
    fname = "John";
    lname = "Smith";
}

//Destructor
Our_Passenger::~Our_Passenger() {
    delete seat;
    seat = nullptr;
}

//Copy Constructor
Our_Passenger::Our_Passenger(const Our_Passenger& other) {
    seat = new Our_Seat(*(other.seat));
    id = other.id;
    phoneNumber = other.phoneNumber;
    fname = other.fname;
    lname = other.lname;
}

//Assignment Operator
Our_Passenger& Our_Passenger::operator=(const Our_Passenger& other) {
    if (this != &other) {
        delete seat;
        seat = new Our_Seat(*(other.seat));
        id = other.id;
        phoneNumber = other.phoneNumber;
        fname = other.fname;
        lname = other.lname;
    }
    return *this;
}

//Setters
void Our_Passenger::setfName(const std::string& firstName) {
    this->fname = firstName;
}

void Our_Passenger::setlName(const std::string& lastName) {
    this->lname = lastName;
}

void Our_Passenger::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Our_Passenger::set_id(int id) {
    this->id = id;
}

void Our_Passenger::set_Seat(int seatRow, char seatColumn, char status, int numRows, int numSeats) { 
    if (seat != nullptr && seatRow >= 0 && seatRow < numRows && seatColumn >= 'A' && seatColumn < 'A' + numSeats) {
        seat->set_row(seatRow);
        seat->set_col(seatColumn);
        seat->set_status(status);
    } else {
        std::cout << "Invalid Seat created" << endl;
    }
}

//Getters
std::string Our_Passenger::getfName()  const {
    return fname;
}

std::string Our_Passenger::getlName()  const {
    return lname;
}

std::string Our_Passenger::getPhoneNumber() const {
    return phoneNumber;
}

int Our_Passenger::get_id() const {
    return id;
}

Our_Seat* Our_Passenger::get_Seat() const {
    return seat;
}