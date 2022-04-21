#include "files.hh"

int main()
{
    file plik;
    std::string title;
    std::string rating;

    plik.open_input_file("test2.csv");

    while(!plik.end_of_file())  // srednio poprawne idk
    {
        plik.read_file(title, rating);
        std::cout <<  title << ' ' <<  rating << std::endl;
    }

    plik.close_input_file();
}