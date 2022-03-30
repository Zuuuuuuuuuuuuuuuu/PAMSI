#include "priority_queue.hh"

bool priority_queue::comparison(int x, int y)
{
    return x < y;
}


bool priority_queue::empty()
{
    return header == nullptr;       // zwraca true jesli header wskazuje na koniec
}


void priority_queue::display_text()
{
    std::cout << header->text;
}


void priority_queue::remove_minimum() 
{
    node *tmp;
    tmp = header;
    if (header->next != nullptr)
    {
        header = tmp->next;
        delete tmp;
    }
    else delete header;
}


void priority_queue::insert(int key, std::string text)
{
    node *element = new node;
    element->key = key;
    element->text = text; // czy to jest potrzebne wlasciwie idk  
    

    // dodawanie na początku kolejki, czyli kiedy pierwsza wart key w kolejce jest wieksza od pobranego klucza
    if (comparison(key, header->key))   // czy comparison(element->key, header->key)?
    {  
        header->prev = element;
        element->next = header;
        header = element;
    }

    else
    {
        node *tmp = header;
        while(!comparison(key, tmp->key) && tmp->next != nullptr)   // dopoki nie znajdujemy wiekszego klucza w kolejce i nie doszlismy do konca kolejki
        {
            tmp = tmp->next;    // przesuwam wskaźnik aż do natrafienia na większy klucz w kolejce
        }
        
        if (comparison(key, tmp->key))  // dodawanie w środku kolejki
        {
            element->next = tmp;
            element->prev = tmp->prev;
            (tmp->prev)->next = element;
            tmp->prev = element;
            tmp = header;       // powrót
        }

        if (!comparison(key, tmp->key)) // dodawanie na końcu kolejki (gdy nie znajdzie w kolejce większego klucza od pobranego)
        {
            tmp->next = element;
            element->prev = tmp;
            element->next = nullptr;
            tmp = header;   // powrót

        }
    }
}