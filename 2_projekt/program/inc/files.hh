/* OBSŁUGA PLIKÓW */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

class file
{
    private:
        std::fstream input_file;    //uchwyty do plików: wejściowego i wyjściowego
        std::fstream output_file;


    public:
        void open_input_file(std::string name_file);
        void read_file(std::string &title, std::string &rating);
        void close_input_file();
        bool end_of_file();
};