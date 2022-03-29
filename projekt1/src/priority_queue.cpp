#include "priority_queue.hh"



// chyba jednak nie
bool priority_queue::comparison(node *new_node, node *tmp)
{
    int key_new = get_key(new_node);
    int key_tmp = get_key(tmp);

    if (key_new > key_tmp)
        return true;
    else return true; 
}

//inline w hh
bool priority_queue::comparison(int x, int y)
{
    return x > y;
}

void priority_queue::insert(int new_node_key, std::string new_node_text)
{
    node *tmp;
    tmp = header;

    while (tmp -> next != nullptr && comparison(new_node_key, tmp -> key))  // dopoki nie doszlismy do konca listy i dopoki new_node_key jest wieksze od klucza, na ktory wskazuje tmp
    {
        tmp = tmp -> next;
    }
    tmp -> next = new node;     // tu i
    tmp -> next -> prev = tmp; // tu jest chyba cos zle?
    // no tu jest cos niedokonczone chyba, potem trzeba by przekazac te rzeczy z pliku do tej funkcji i wpisac
    // je do odpowiednich pól w new_node
}


void priority_queue::remove_minimum()
{
    node *tmp;
    tmp = get_next(header);
    int key1 = get_key(header);
    int key2 = get_key(tmp);

    if (comparison(key2, key1)) // jezeli wezel 2 ma wiekszy klucz niz wezel 1, to wszystko jest git i remove - czyli usun i wypisz text z wezla 1
    {
        display_and_remove(tmp);
    }
    else
    {
        std::cout << "Lista nie jest uporządkowana z niewiadomych powodów" << std::endl;
    }

}

// algorytm
// przechodzimy po kolejnych node'ach
// wywolujemy funkcje get_key
// porownujemy pierwszy i nastepny node
// jesli jest mniejszy (a jest) to wypisujemy go na stdout, czyli >> przeciazyc chyba trzeba
//
//



void priority_queue::display_and_remove(node *tmp)
{
    std::cout << tmp -> text;
    tmp -> prev = tmp -> next;
    tmp -> next = tmp -> prev;
    delete tmp -> next;
    delete tmp -> prev;
// no nie bałdzo wiem jak z tymi setterami i po co 
}

// algorytm ---- chcemy usunac tmp
// ale najpierw chyba wyswietlic !!
// tmp get prev - set next - tmp get next ----- tmp poprzedni ustawiamy teraz na tmp nast
// tmp get next - set prev - tmp get prev ----- tmp nast ustawiamy teraz na tmp prev
// usunac wskazniki elementu