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
    node *header = nullptr;
    bool comparison(int x, int y);

public:
    void insert(int key, std::string text);
    void display_text();
    void remove_minimum(); 
    bool empty();
};

#endif