#include "files.hh"

void file::open_input_file(std::string name_file)
{
    input_file.open(name_file, std::ios::in);      // otwieranie pliku do czytania
}


void file::open_output_file(std::string name_file)
{
    output_file.open(name_file, std::ios::out);    // otwieranie pliku do zapisu
}


void file::read_file(std::string &title, std::string &rating)
{
    std::string numbering;
    std::getline(input_file, numbering, ',').clear();

    char mark = input_file.peek();
    
    if (mark == '\"') //jezeli znajdziesz cudzyslow to zczytaj do konca cudzyslowu tytuł i dopiero po przecinku ocenę
    {
        input_file.get();   // jak to rozwiazac ladniej ( czy zostawiam cudzyslow czy nie ) -- bez tego zczytuje tylko spacje bo do pierwszego "
        std::getline(input_file, title, '\"');
        input_file.get();
        std::getline(input_file, rating);
    }
    else
    {
        std::getline(input_file, title, ',');   // zczytanie tytułu aż do przecinka (budowa pliku csv)
        std::getline(input_file, rating);
    }
    // co z nazwami kolumn
}


// void file::write_out_file(const std::string &text)
// {
//     out_file << text;
// }


void file::close_input_file()
{
    input_file.close();
}


void file::close_output_file()
{
    output_file.close();       
}

bool file::end_of_file()
{
    return input_file.eof();   // zwraca prawde, jesli eof
}