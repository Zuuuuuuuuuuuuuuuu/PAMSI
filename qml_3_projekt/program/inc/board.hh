#pragma once

#include <iostream>
const int size_one_side = 300;

class Board //: public sf::Drawable
{
    private:
        

    public:
        void initialize_board(int &cells);   //size --- the number of cells
        void is_clicked();
        void get_position_on_board();
};