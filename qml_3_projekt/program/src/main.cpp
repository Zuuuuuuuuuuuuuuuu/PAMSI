#include "cross.hh"
#include "circle.hh"
#include "board.hh"

#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    int rozmiar;
    Board plansza;

    std::cout << "Podaj rozmiar planszy: ";
    std::cin >> rozmiar;
    plansza.initialize_board(rozmiar);
    std::cout << "Rozmiar planszy to kwadrat: " << rozmiar * size_one_side << " x " << rozmiar * size_one_side << std::endl;

    return 0;
}