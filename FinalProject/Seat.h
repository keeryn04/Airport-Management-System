#ifndef OUR_SEAT
#define OUR_SEAT

class Our_Seat {
    public:
        Our_Seat();

        void set_row(int row);
        int get_row() const;

        void set_col(char col);
        char get_col() const;

        void set_status(char status);
        char get_status() const;

    private:
        int row;
        char seat;
        char status;
};

#endif