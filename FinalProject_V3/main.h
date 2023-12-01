#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip> 
using namespace std;

#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"

//main.cpp functions
Our_Flight populate_flight(const char* filename); //Fills class instances with info from text file, assigning to proper places

void cleanStandardInputStream(); //Clears buffer, used for invalid input

void press_enter(); //Pauses until enter

int menu(); //Output for user

void display_header(); //Output for user

string trim_trailing_spaces(string& s); //Cleans up info from file, allows proper saving

void displaySeatMap(Our_Flight& f); //Option 1 of menu, used to display seatmap of flight

void displayPassenger(Our_Flight& f); //Option 2 of menu, Displays all passengers on flight

void addPassenger(Our_Flight& f); //Option 3 of menu, Adds an instance of passenger to flight, including seat pointer

