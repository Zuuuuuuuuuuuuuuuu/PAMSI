#ifndef OBSLUGA_PLIKOW.HH
#define OBSLUGA_PLIKOW.HH

#include <iostream>
#include <string.h>

class file
{
    public:
    void open_file(char argv[1]);
    void read_file(int &key, std::string &text);
};




#endif