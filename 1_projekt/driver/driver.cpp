/* driver - prezentowanie diałania struktury danych */

#include "priority_queue.hh"
#include <iostream>

int main()
{
    int opcja;
    int klucz;
    priority_queue kolejka;
    std::string tekst;

    while(opcja != 6)
    {
        std::cout << "\nDostępne metody dla kolejki priorytetowej:\n1. INSERT (rozszerzona metoda push) \n2. REMOVE_MINIMUM (pop) \n";
        std::cout << "3. EMPTY \n4. SIZE \n5. DISPLAY_TEXT (top) \n6. Zakończenie działania programu\nProszę wybrać jedną z dostępnych opcji: ";
        
       
        std::cin >> opcja;


        switch (opcja)
        {
            case 1:     // insert
                std::cout << "\nProszę podać element do wpisania do kolejki w formie: klucz_spacja_tekst: ";
                std::cin >> klucz;
                std::cin.ignore(); 
                std::getline(std::cin, tekst);
                kolejka.insert(klucz, tekst);
                std::cout << "Element został wpisany do kolejki.\n";
                break;
            
            case 2:     // remove_minimum
                kolejka.remove_minimum();
                std::cout << "\nElement z początku kolejki został usunięty.\n";
                break;
            
            case 3:     // empty
                if (kolejka.empty())
                {
                    std::cout << "\nKolejka jest pusta.\n";
                }
                else std::cout << "\nKolejka nie jest pusta.\n";
                break;
            
            case 4:     // size
                std::cout << "\nAktualny rozmiar kolejki: " << kolejka.size() << std::endl;
                break;
            
            case 5:     // return_minimum
                std::cout << "Wartość (tekst) pierwszego elementu w kolejce: ";
                kolejka.display_text();
                std::cout << std::endl;
                break;

            case 6:     // koniec dzialania
                break;

            default:
                std::cout << "\nUps... Nie ma takiej opcji!\n";
                break;
        }
    }
}