#include "obsluga_plikow.hh"
#include "priority_queue.hh"
#include <iostream>
//int argc, char *argv[]
int main()
{
    priority_queue kolejka;
    file plik;
    int klucz;
    std::string tekst;
    plik.open_in_file("list.txt");
    plik.open_out_file("kubus");

   while (!plik.end_of_file())
    {
       plik.read_file(klucz, tekst);
       kolejka.insert(klucz, tekst);
        kolejka.display_text();
        kolejka.remove_minimum();
    }

    // kolejka.display_text();
    // kolejka.remove_minimum();
    // kolejka.display_text();
    // plik.read_file(klucz, tekst);
    // kolejka.insert(klucz, tekst);
    // kolejka.display_text();
    // kolejka.remove_minimum();


  //  while(!kolejka.empty())
  //  {
  //    kolejka.display_text();
  //    kolejka.remove_minimum();
  //  }
    
    //kolejka.remove_minimum();
    
    
    //while (!kolejka.empty())
    //{
    //    kolejka.display_text();
    //    plik.write_out_file(tekst);
    //    kolejka.remove_minimum();
    //}
   
    plik.close_in_file();
    plik.close_out_file();

}