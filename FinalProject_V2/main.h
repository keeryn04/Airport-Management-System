//g++ -o main.out main.cpp Flight.cpp Passenger.cpp Seat.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"

//main.cpp functions
Our_Flight populate_flight(const char* filename);

void cleanStandardInputStream();

void press_enter();

int menu();

void display_header();

string trim_trailing_spaces(string& s);

void displaySeatMap(Our_Flight& f);

void displayPassenger(Our_Flight& f);

void addPassenger();


