#include <iostream>
using namespace std;

#include "main.h"

//Default Constructor
Our_Seat::Our_Seat() {
    row = 1;
    seat = 'A'; 
    status = 'O';
}

//Setters
void Our_Seat::set_row(int row) {
    this->row = row;
}

void Our_Seat::set_col(char col) {
    this->seat = col;
}

void Our_Seat::set_status(char status) {
    this->status = status;
}

//Getters
int Our_Seat::get_row() const {
    return row;
}

char Our_Seat::get_col() const {
    return seat;
}

char Our_Seat::get_status() const {
    return status;
}