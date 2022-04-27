#include "files.hh"
#include <vector>

int main()
{
    file plik;
    std::string title;
    std::string rating;
    std::vector<std::pair<std::string, std::string>> structure;

    plik.open_input_file("test3.csv");

    // while(!plik.end_of_file())  // srednio poprawne idk !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // {
    //     plik.read_file(title, rating);
    //     std::cout <<  title << ' ' <<  rating  << std::endl;
    //     structure.push_back( std::make_pair (title, rating) );  // wpisywanie pary do wektora
    // }


    while(true)  // srednio poprawne idk !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        plik.read_file(title, rating);
        structure.push_back( std::make_pair (title, rating) );  // wpisywanie pary do wektora
        std::cout <<  title << ' ' <<  rating  << std::endl;
        if (plik.end_of_file() )
        {
            std::cout << "Koniec pliku" << std::endl;
            break;
        }
    }

    plik.close_input_file();
    std :: cout << structure.size() << '\n';

    // pętla przeszukiwania pustych pól w vectorze w rating
    for (int i = 0; i< structure.size(); ++i)
    {
        if ( structure[i].second.empty() )      // znalezienie pustego pola rating
        {
            std::cout << "Pusta ocena jest tu: " << structure[i].first << " " << structure[i].second << std::endl;
            //structure[i].first.clear();         // wyczyszczenie 
            //structure[i].second.clear();
            structure.erase(structure.begin() + i--);
        }
        else 
        {
            std::cout << i << " " << "Nie ma pustych pól w rating" << std::endl;
        }

    }
    
    for ( int i = 0; i< structure.size(); ++i )
    {
        std::cout << structure[i].first  << " " <<  structure[i].second  << std::endl;
    }
}