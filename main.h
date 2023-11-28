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

void pressEnter();

int menu();

void display_header();


