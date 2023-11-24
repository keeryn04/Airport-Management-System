#include <iostream>
using namespace std;

#include "Seat.h"

int main(void) {
    Our_Seat mySeat;

    mySeat.set_row(5);
    mySeat.set_col('B');

    int row = mySeat.get_row();
    char col = mySeat.get_col();

    cout << row << col;
    return 0;
}