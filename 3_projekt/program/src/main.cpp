#include "cross.hh"
#include "circle.hh"
#include "board.hh"

#include <iostream>
#include <SFML/Graphics.hpp>

const int one_side_board_size = 800;

void draw_board(sf::RenderWindow &window, int cells)
{
    int one_cell_size = window.getSize().x / cells;
    int tmp = one_cell_size;
    sf::RectangleShape rectangle(sf::Vector2f(5, one_side_board_size));
    rectangle.setFillColor(sf::Color::Black);

    for (int i = 1; i <= cells - 1; i++)
    {
        rectangle.setPosition(one_cell_size, 0);
        window.draw(rectangle);
        one_cell_size = one_cell_size + tmp;
    }
    
    one_cell_size = window.getSize().x / cells;
    rectangle.rotate(-90);
    for (int i = 1; i <= cells - 1; i++)
    {
        rectangle.setPosition(0, one_cell_size);
        window.draw(rectangle);
        one_cell_size = one_cell_size + tmp;
    }
}


int main()
{
    int number_of_cells;
    std::cout << "Podaj rozmiar planszy (liczbę komórek w rzędzie): ";
    std::cin >> number_of_cells;
    char tab[number_of_cells][number_of_cells];

    sf::RenderWindow board(sf::VideoMode(one_side_board_size, one_side_board_size), "Tic tac toe");
    
    sf::Font font;
    if (!font.loadFromFile("ARIBL0.ttf"))
    {
        std::cout << "yyy\n";
    }
    sf::Text text;
    text.setFont(font);
    text.setString("O");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Black);
    // window.draw(text);
        


    while (board.isOpen())
    {
        sf::Event event;

        // if (event.type == sf::Event::Resized)       // popracowac nad tym: zczytywac rozmiar okna i skalowac
        // {
        //     board.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        //     sf::RenderWindow board(sf::VideoMode(event.size.width, event.size.height), "Tic tac toe");
        //     std::cout << "\n" << board.getSize().x << std::endl;
        //     board.clear(sf::Color::White);
        //     draw_board(board, number_of_cells);
        //     board.display();
        // }

        while (board.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                board.close();
        }

        

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                int one_cell_size = board.getSize().x / number_of_cells;
                int row = position.x / one_cell_size;
                int column = position.y / one_cell_size;
                tab[row][column] = 'O';
                text.setPosition(row*one_cell_size + one_cell_size/number_of_cells, column*one_cell_size + one_cell_size/number_of_cells );
            }
        }
        board.clear(sf::Color::White);
        draw_board(board, number_of_cells);
        board.draw(text);
        board.display();

        
    }
    
    

    return 0;
}