#ifndef PRIORITY_QUEUE.HH
#define PRIORITY_QUEUE.HH

#include <iostream>

struct node
{
    int key;
    std::string text;
    node *prev = nullptr;
    node *next = nullptr;
};

class priority_queue
{

private:
    //node element;
    node *header = nullptr;
    
public:
    
    inline node *get_next(node *tmp)
    {
        return tmp -> next;
    }

    inline node *get_prev(node *tmp)
    { 
        return tmp -> prev;
    }

    
    bool comparison(node *new_node, node *tmp);
    bool comparison(int x, int y);


    inline int get_key(node *element) { return element -> key; }
    
    // void set_next(node *element, ); {}
    // void set_prev();
    
    void insert(int key, std::string text);

    // insert lub set_element + add_after:
    // void add_after(node p, node element);

    void display_and_remove(node *tmp);
    void remove_minimum();
    bool empty();

    
};

#endif