// #include "obsluga_plikow.hh"
// #include "priority_queue.hh"
// #include <iostream>
// #include <chrono>

// int main()
// {
//   std::fstream plik("plik.txt", std::ios::out);
//   std::fstream dane("dane.txt", std::ios::out);
//   file kuba;  
//   int klucz;
//   priority_queue kolejka;
//   std::string tekst;

//   for (int liczba=1; liczba <= 100000 ; liczba=liczba+10)
//   {
//     plik << liczba << " lalala jakis tekst\n";
//   }

//   plik.close();
//   kuba.open_in_file("plik.txt");
//   while (!kuba.end_of_file())
//   {
//     kuba.read_file(klucz, tekst);
//     kolejka.insert(klucz, tekst);
//   }
    
//     // tu pisze co chce mierzyc
//     while (!kolejka.empty())
//     {
//     auto begin = std::chrono::high_resolution_clock::now();
//     kolejka.remove_minimum();
//     auto end = std::chrono::high_resolution_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
//     dane << elapsed.count() << "\n";

//     }

    
// }