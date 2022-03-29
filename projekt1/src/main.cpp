
#include<iostream>
#include<fstream>
#include<string>

int main(){

    std :: fstream plik("../list.txt", std :: ios :: in);
    int liczba;
    std :: string tekst;

    plik >> liczba;
    std :: getline(plik,tekst);
    std :: cout << "liczba " << liczba << std :: endl;
    std :: cout << "tekst " << tekst << std :: endl;

}



    //while ( to w mainie --> wywolanie funkcji zczytania jednej linijki (/sekwencji) i potem az do eof (wywolanie f. eof) wpisanie sekwencji do kolejki )

// zmienna bool fstream plik_z_wiadomoscia (list) EOF
// do zmiennej pomocniczej key i text
// tworzenie węzła header = new node -- tworzenie nowego węzła
// header -> key = zmienna z wart klucz
// header -> text = zmienna z textem



// słowo kluczowe new 
//prev tego nowego musi wskazywac na wczesniejszy node
// next 
// new node.prev = last node
// last node next = new node



// head -> next = new node
