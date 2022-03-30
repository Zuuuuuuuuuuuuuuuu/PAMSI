#ifndef OBSLUGA_PLIKOW.HH
#define OBSLUGA_PLIKOW.HH

#include <iostream>
#include <string>
#include <fstream>

class file
{
    private:
        std::fstream in_file;       // uchwyty do plików
        std::fstream out_file;

    public:
        void open_in_file(std::string name_file);
        void open_out_file(std::string name_file);
        void read_file(int &key, std::string &text);
        void write_out_file(const std::string &text);
        void close_in_file();
        void close_out_file();
        bool end_of_file();
};




#endif