#include "obsluga_plikow.hh"
#include "priority_queue.hh"

#include <iostream>

int main(int argc, char *argv[])
{
  priority_queue kolejka;
  file plik;
  int klucz;
  std::string tekst;
  plik.open_in_file(argv[1]);
  plik.open_out_file("uporzadkowany_list");

  while (!plik.end_of_file())
  {
    plik.read_file(klucz, tekst);
    kolejka.insert(klucz, tekst);
  }
  
  while(!kolejka.empty())
  {
    kolejka.display_text();
    plik.write_out_file(kolejka.return_minimum());
    kolejka.remove_minimum();
  }
  std::cout << "\n";

  plik.close_in_file();
  plik.close_out_file();
}