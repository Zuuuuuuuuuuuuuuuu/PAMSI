#include "files.hh"

void file::open_input_file(std::string name_file)
{
    input_file.open(name_file, std::ios::in);      // otwieranie pliku do czytania
}


void file::read_file(std::string &title, std::string &rating)
{
    int position1, position2;
    std::string line;

    std::getline(input_file, line);
    position1 = line.find_first_of(",");
    position2 = line.find_last_of(",");
    title = line.substr(position1 + 1, position2 - position1 - 1);   // weźmie wszystko po przecinku (pos1+1) do ostatniego przecinka
    rating = line.substr(position2 + 1, line.length() - position2);
}


// void file::read_file(std::string &title, std::string &rating)
// {
//     std::string numbering;
//     std::getline(input_file, numbering, ',').clear();

//     char mark = input_file.peek();
//     std::string buffer1;
//     std::string buffer2;
    
//     if (mark == '\"') //jezeli znajdziesz cudzyslow to zczytaj do konca cudzyslowu tytuł i dopiero po przecinku ocenę
//     {
//         input_file.get();   // jak to rozwiazac ladniej ( czy zostawiam cudzyslow czy nie ) -- bez tego zczytuje tylko spacje bo do pierwszego "
//         std::getline(input_file, title, '\"');
//         if (input_file.peek() == '\"')
//         {
//             input_file.get();
//             std::getline(input_file, buffer1, '\"');
//             if (input_file.peek() == '\"')
//             {
//                 input_file.get();
//                 std::getline(input_file, buffer2, '\"');
//             }
//             title = title + buffer1 + buffer2;
//         }
//         input_file.get();
//         std::getline(input_file, rating);
//     }
//     else
//     {
//         std::getline(input_file, title, ',');   // zczytanie tytułu aż do przecinka (budowa pliku csv)
//         std::getline(input_file, rating);
//     }
//     // co z nazwami kolumn
// }


void file::close_input_file()
{
    input_file.close();
}


bool file::end_of_file()
{
    return input_file.eof();   // zwraca prawde, jesli eof
}