#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

constexpr int one_side_number_of_cells = 800;
constexpr int infinity = 900000000;
constexpr int minus_infinity = -900000000;

char winner = '-';


int rate_positions(int &number_of_cells, char **tab)       // ocenia pozycje albo po zakończeniu gry, albo podczas analizy, gdy głębokość=0
{
    int position_rating = 0;
    int tmp = 0;

    for (int i=0; i < number_of_cells; i++)                // przechodzenie po rzędach
    {
        tmp = 0;
        for (int j=0; j < number_of_cells; j++)
        {
            if (tab[i][j] == 'X')
               tmp++;
            
            else if (tab[i][j] == 'O')
            {
                tmp = 0;
                break;
            } 
        }

        if (tmp)
            position_rating += pow(10, tmp);    // jakaś bardzo duża liczba, jeżeli jest fajna pozycja X (ai) -- np. dwa X w rzędzie
    }

    
    for (int i=0; i < number_of_cells; i++)                // przechodzenie po kolumnach
    {
        tmp = 0;
        for (int j=0; j < number_of_cells; j++)
        {
            if (tab[j][i] == 'X')
               tmp++;
            
            else if (tab[j][i] == 'O')
            {
                tmp = 0;
                break;
            } 
        }
        
        if (tmp)
            position_rating += pow(10, tmp);    // jakaś bardzo duża liczba
    }

    tmp = 0;
    for (int j=0; j < number_of_cells; j++)         // przechodzenie po przekątnej w jedną stronę (te same współrzędne)
    {
        if (tab[j][j] == 'X')
           tmp++;
        
        else if (tab[j][j] == 'O')
        {
            tmp = 0;
            break;
        } 
    
        if (tmp)
            position_rating += pow(10, tmp);    // jakaś bardzo duża liczba
    }
    

    for (int i = 0, j = number_of_cells - 1; i < number_of_cells; i++, j--)     // przechodzenie po przekątnej w drugą stronę 
    {
        tmp = 0;
        if (tab[i][j] == 'X')
            tmp++;

        else if (tab[i][j] == 'O')
        {
            tmp = 0;
            break;
        }

        if (tmp)
            position_rating += pow(10, tmp);
    }
    return position_rating;
}




bool check_win(const int &number_of_cells, char **tab)
{
    int circles = 0;
    int crosses = 0;

    for (int i = 0; i < number_of_cells; i++)       // sprawdzenie rzędów
    {
        for (int j = 0; j < number_of_cells; j++)
        {
            if (tab[i][j] == 'X')
                crosses++;
            else if (tab[i][j] == 'O')
                circles++; 
        }

        if (crosses == number_of_cells)     // jeśli wygrana
        {
            winner = 'X';
            return true;
        }

        if (circles == number_of_cells)
        {
            winner = 'O';
            return true;
        }

    circles = 0;
    crosses = 0;
    }

    circles = 0;
    crosses = 0;

    for (int i = 0; i < number_of_cells; i++)       // sprawdzanie kolumn
    {
        for (int j = 0; j < number_of_cells; j++)
        {
            if (tab[j][i] == 'X')
                crosses++;
            else if (tab[j][i] == 'O')
                circles++; 
        }
    
        if (crosses == number_of_cells)     // jeśli wygrana
        {
            winner = 'X';
            return true;
        }

        if (circles == number_of_cells)
        {
            winner = 'O';
            return true;
        }
    
    circles = 0;
    crosses = 0;
    }

    circles = 0;
    crosses = 0;

    for (int j = 0; j < number_of_cells; j++)               // sprawdzenie przekątnej (te same współrzędne)
        {
            if (tab[j][j] == 'X')
                crosses++;
            else if (tab[j][j] == 'O')
                circles++; 
        }
    
        if (crosses == number_of_cells)     // jeśli wygrana
        {
            winner = 'X';
            return true;
        }

        if (circles == number_of_cells)
        {
            winner = 'O';
            return true;
        }


    circles = 0;
    crosses = 0;

    for (int i = 0, j = number_of_cells - 1; i < number_of_cells; i++, j--)     // sprawdzenie przekątnej w drugą stronę
    {
        if (tab[i][j] == 'X')
            crosses++;
        else if (tab[i][j] == 'O')
            circles++;
    }
    
        if (crosses == number_of_cells)     // jeśli wygrana
        {
            winner = 'X';
            return true;
        }

        if (circles == number_of_cells)
        {
            winner = 'O';
            return true;
        }
    
    winner = '-';
    return false;
}

bool is_finished(int &number_of_cells, char **tab)
{
    for (int i=0; i < number_of_cells; i++)
    {
        for (int j=0; j < number_of_cells; j++)
        {
            if (tab[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}


int minimax_alpha_beta(char current_player, int depth, int a, int b, int &number_of_cells, char **tab)
{
    check_win(number_of_cells, tab);

    if (winner != '-')                
    {
        if (current_player == 'X')      
            return pow(10,8);            // max wartosc
        else
            return -pow(10,8);       // min wartosc
    }

    if (is_finished(number_of_cells, tab) || depth == 0)
    {
        if (current_player == 'X')
            return rate_positions(number_of_cells, tab);    // zwraca position_rating
        else
            return -rate_positions(number_of_cells, tab);
    }

    int best_score;

    if (current_player == 'X')
    {
        current_player = 'O';          // zamiana graczy
        best_score = infinity;
    }
    else
    {
        current_player = 'X';
        best_score = -infinity;
    }

    int tmp;
    for (int i = 0; i < number_of_cells; i++)
    {
        for (int j = 0; j < number_of_cells; j++)
        {
            if (tab[i][j] == '-')
            {
                if (current_player == 'X')
                {
                    tab[i][j] = 'X';
                    tmp = minimax_alpha_beta(current_player, depth-1, a, b, number_of_cells, tab);  //rekurencyjnie
                    if (best_score < tmp)
                        best_score = tmp;
                    
                    if (a < best_score)     // odcinanie gałęzi
                        a = best_score;

                    tab[i][j] = '-';
                    if (a >= b)
                        return best_score;
                }
                else
                {
                    tab[i][j] = 'O';
                    tmp = minimax_alpha_beta(current_player, depth-1, a, b, number_of_cells, tab);
                    if (best_score > tmp)
                        best_score = tmp;
                    
                    if (a > best_score)
                        a = best_score;

                    tab[i][j] = '-';
                    if (a >= b)
                        return best_score;
                }
            }
        }
    }
    return best_score;
}



std::pair<int, int> best_ai_move(int depth, int &number_of_cells, char **tab)
{
    int best_score = minus_infinity;
    int tmp;
    int set_i;
    int set_j;

    for (int i = 0; i < number_of_cells; i++)
    {
        for (int j = 0; j < number_of_cells; j++)
        {
            if (tab[i][j] == '-')
            {
                tab[i][j] = 'X';
                tmp = minimax_alpha_beta('X', depth, -infinity, infinity, number_of_cells, tab);
                tab[i][j] = '-';
                if (tmp > best_score)
                {
                    best_score = tmp;
                    set_i = i;
                    set_j = j;
                }
            }
        }
    }

    if (set_i < number_of_cells && set_j < number_of_cells)
        tab[set_i][set_j] = 'X';

    return std::make_pair(set_i, set_j);
}



void draw_board(sf::RenderWindow &window, int cells)
{
    int one_cell_size = window.getSize().x / cells;
    int tmp = one_cell_size;
    sf::RectangleShape rectangle(sf::Vector2f(5, one_side_number_of_cells));
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
    std::pair<int, int> coordinates_best_ai_move;
    int number_of_cells;
    int depth;
    std::cout << "KÓŁKO I KRZYŻYK. Podaj rozmiar planszy (liczbę komórek w rzędzie): ";
    std::cin >> number_of_cells;
    std::cout << "Podaj poziom trudności (głębokość): ";
    std:: cin >> depth;

    // TWORZENIE DYNAMICZNEJ TABLICY DWUWYMIAROWEJ I WPISYWANIE W KAŻDE POLE SPACJI
    char **tab = new char * [number_of_cells];
    for (int i=0; i<number_of_cells; i++)
    {
        tab[i] = new char[number_of_cells];
    }
    
    for (int i=0; i<number_of_cells; i++)
    {
        for (int j=0; j<number_of_cells; j++)
        {
            tab[i][j] = '-';
        }
    }

    // TWORZENIE PLANSZY
    sf::RenderWindow board(sf::VideoMode(one_side_number_of_cells, one_side_number_of_cells), "Tic tac toe");
    
    int one_cell_size = board.getSize().x / number_of_cells;

    // ŁADOWANIE CZCIONKI
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Nie mamy takiej czcionki\n";
    }

    // USTAWIENIA KÓŁKA I KRZYŻYKA
    sf::Text circle;
    circle.setFont(font);
    circle.setString("O");
    circle.setCharacterSize(one_cell_size);
    circle.setFillColor(sf::Color::Black);
    circle.setLineSpacing(0);
    circle.setLetterSpacing(0);

    
    sf::Text cross;
    cross.setFont(font);
    cross.setString("X");
    cross.setCharacterSize(one_cell_size);
    cross.setFillColor(sf::Color::Black);
    cross.setLineSpacing(0);
    cross.setLetterSpacing(0);

    // WYŚWIETLENIE NARYSOWANEJ PLANSZY I GŁÓWNA PĘTLA
    board.clear(sf::Color::White);
    draw_board(board, number_of_cells);
    board.display();
    

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

                if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(board);
                    int column = position.x / one_cell_size;
                    int row = position.y / one_cell_size;
                    tab[row][column] = 'O';
                    circle.setPosition(column * one_cell_size + (circle.getCharacterSize() * 0.1), row * one_cell_size + (circle.getCharacterSize() * -0.13));       // centrowanie
                    board.draw(circle);
                    coordinates_best_ai_move = best_ai_move(depth, number_of_cells, tab);
                    cross.setPosition(coordinates_best_ai_move.second * one_cell_size + (circle.getCharacterSize() * 0.1), coordinates_best_ai_move.first * one_cell_size + (circle.getCharacterSize() * -0.13));       // centrowanie
                    board.draw(cross);
                    board.display();
                    
                    if (check_win(number_of_cells, tab))
                        std::cout << "Gra wygrana, winner: " << winner << std::endl;
                    else std::cout << "Remis, winner: " << winner << std::endl;

                    if (is_finished(number_of_cells, tab))
                        std::cout << "Gra skończona\n";

                    for(int i = 0;i<number_of_cells;++i)
                    {
                        for(int j = 0; j<number_of_cells;++j)
                        {
                            std::cout<<tab[i][j]<<'\t';
                        }
                        std::cout<<std::endl;
                    }              
                }
            }
        }

        

        
    }
return 0;
}