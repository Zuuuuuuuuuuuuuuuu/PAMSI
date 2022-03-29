#include "obsluga_plikow.hh"


void file::open_in_file(std::string name_file)
{
    in_file.open(name_file, std::ios::in);      // otwieranie pliku do czytania
}



void file::open_out_file(std::string name_file)
{
    out_file.open(name_file, std::ios::out);    // otwieranie pliku do zapisu
}



void file::read_file(int &key, std::string &text)
{
    in_file >> key;
    std::getline(in_file, text);
}



void file::write_out_file(const std::string &text)
{
    out_file << text;
}


void file::close_file()
{
    in_file.close();
    out_file.close();       // on wie które to in_file i które out_file z funkcji open
}


bool file::end_of_file()
{
    return in_file.eof();   // zwraca prawde, jesli eof
}