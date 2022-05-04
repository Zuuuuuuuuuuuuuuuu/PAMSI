#include "files.hh"
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

/******************************************************/
/*                                                    */
/* MERGE_SORT - SORTOWANIE PRZEZ SCALANIE - funkcje   */
/*                                                    */
/******************************************************/

void merge(std::pair<std::string, float> array[], int left, int middle, int right)    // funkcja do scalania sub-tablic
{
    // podział tablicy na dwie części
    int sub_array1 = middle - left + 1;           // liczba elementów do pierwszej i drugiej sub-tablicy
    int sub_array2 = right - middle;

    std::pair<std::string, float> *left_array = new std::pair<std::string, float>[sub_array1];    // tworzenie nowych dynamicznych sub-tablic o zadanej liczbie elementów
    std::pair<std::string, float> *right_array = new std::pair<std::string, float>[sub_array2];
    
    for (int i = 0; i < sub_array1; i++)          //  wpisywanie odpowiednich elementów z podstawowej tablicy array do lewej sub-tablicy
    {
        left_array[i].first = array[left + i].first;
        left_array[i].second = array[left + i].second;
    }
    
    for (int i = 0; i < sub_array2; i++)          //  wpisywanie odpowiednich elementów z podstawowej tablicy array do prawej sub-tablicy
    {
        // right_array[i].first = array[middle + 1 + i].first; // TU SEG FAULT 
        // right_array[i].second = array[middle + 1 + i].second;
        right_array[i] = array[middle + i];
    }

    int index_sub_array1 = 0;                     // pierwsze indeksy sub-tablic 
    int index_sub_array2 = 0;
    int index_merged_arrays = left;               // pierwszy indeks scalonej tablicy --> tak, żeby nie zepsuć całej wejściowej tablicy, jeśli do sortowania będzie brana jej część

    // sortowanie --> wkładanie odpowiednich elementów do wyjściowej tablicy
    while (index_sub_array1 < sub_array1 && index_sub_array2 < sub_array2)          // dopóki w obydwu sub-tablicach coś jest
    {
        if (left_array[index_sub_array1].second <= right_array[index_sub_array2].second )         // jeżeli dany element lewej tablicy jest mniejszy ...
        {
            array[index_merged_arrays].first = left_array[index_sub_array1].first;              // przypisanie do tablicy wyjściowej mniejszego elementu // TU SEG FAULT 
            array[index_merged_arrays].second = left_array[index_sub_array1].second;
            index_sub_array1++;
        }

        else                                                                        // jeżeli jest większy w prawej ...
        {
            array[index_merged_arrays] = right_array[index_sub_array2];
            index_sub_array2++;
        }
        index_merged_arrays++;
    }

    // wkładanie "pozostałości"
    
    while (index_sub_array1 < sub_array1)                                           // jeśli coś zostało w lewej sub-tablicy
    {
        array[index_merged_arrays] = left_array[index_sub_array1];
        index_sub_array1++;
        index_merged_arrays++;
    }


    while (index_sub_array2 < sub_array2)                                           // jeśli coś zostało w prawej sub-tablicy
    {
        array[index_merged_arrays] = right_array[index_sub_array2];
        index_sub_array2++;
        index_merged_arrays++;
    }
}

void merge_sort(std::pair<std::string, float> array[], int const begin, int const end)                      // funkcja do sortowania przez scalanie
{   
    // krok podstawowy
    if (begin >= end)                                    // jeżeli po dzieleniu sub-tablic zostanie 1 element --> zostanie zwrócony
    {
        return;
    }

    int middle = begin + (end - begin) / 2;             // podzielenie wejściowej tablicy 
    merge_sort(array, begin, middle);                   // rekurencyjne wywołanie funkcji dla 2 powstałych sub-tablic 
    merge_sort(array, middle + 1, end);
    merge(array, begin, middle, end);
}



/******************************************************/
/*                                                    */
/* QUICKSORT - SORTOWANIE SZYBKIE - funkcje           */
/*                                                    */
/******************************************************/

// int partition(float array[], int begin, int end)
// {
//     int middle = (end + begin) / 2;     // środek w tablicy
//     int pivot = array[middle];          // wartość wyznaczonego elementu środkowego tablicy jako piwot (E)

//     int count = 0;
//     for (int i = begin; i <= end; i++)  // ile elementów w tablicy jest <= piwot --> L
//     {
//         if (array[i] <= pivot)
//         {
//             count++;
//         }
//     }

//     int new_index_pivot = begin + count - 1;            // -1 bo w powyższej pętli wliczono piwot; nowy indeks piwota
//     std::swap(array[new_index_pivot], array[middle]);   // E w dobrym miejscu

    
//     // sortowanie co po lewej (L) i co po prawej (G) stronie piwota
//     int i = begin, j = end;

//     while ( i < new_index_pivot && j > new_index_pivot )
//     {
//         while (array[i] <= pivot)
//         {
//             i++;
//         }

//         while (array[j] > pivot)
//         {
//             j--;
//         }

//         if ( i < new_index_pivot && j > new_index_pivot)
//         {
//             std::swap(array[i++], array[j--]);              // std::swap(array[i], array[j]); i++; j++;
//         }
//     }
//     return new_index_pivot;
// }


// void quicksort(float array[], int begin, int end)
// {
//     if (begin >= end)   //krok podstawowy
//     {
//         return;
//     }

//     int p_index = partition(array, begin, end);
//     quicksort(array, begin, p_index-1);
//     quicksort(array, p_index + 1, end);
// }



/******************************************************/
/*                                                    */
/*  - SORTOWANIE  - funkcje   */
/*                                                    */
/******************************************************/







int main()
{

/******************************************************/
/*                                                    */
/*          ZADANIE 1 - PRZESZUKIWANIE PLIKU          */
/*                                                    */
/******************************************************/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11 usuniecie pierwszego wiersza

    file plik;
    std::fstream dane("przefiltrowane_dane_10tys.txt", std::ios::out);    // plik do zapisu czasu
    std::fstream dane1("przefiltrowane_dane_100tys.txt", std::ios::out);    // plik do zapisu czasu
    std::fstream dane2("przefiltrowane_dane_500tys.txt", std::ios::out);    // plik do zapisu czasu
    std::fstream dane3("przefiltrowane_dane_max.txt", std::ios::out);    // plik do zapisu czasu

    std::string title;
    std::string rating;
    std::vector<std::pair<std::string, std::string>> structure;

    plik.open_input_file("projekt2_dane.csv");


    while(true)
    {
        plik.read_file(title, rating);
        structure.push_back( std::make_pair (title, rating) );  // wpisywanie pary do wektora
        if (plik.end_of_file()) 
        {
            break;
        }
    }

    plik.close_input_file();

    // pętla przeszukiwania pustych pól w vectorze w rating
        for (int i = 0; i< structure.size(); ++i)
    {
        if ( structure[i].second.empty() )      // znalezienie pustego pola rating
        {
            structure.erase(structure.begin() + i--);
        }
    }

    // auto begin = std::chrono::high_resolution_clock::now();
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // dane << elapsed.count() << "\n";
    // std::cout << "\nCzas: " << elapsed.count() << std::endl;


    // konwersja string na float
    std::vector<std::pair<std::string, float>> structure2;
    for (int i = 0; i < structure.size(); ++i)
    {
        float rating = std::stof(structure[i].second);
        structure2.push_back( std::make_pair (title, rating) );
    }





/******************************************************/
/*                                                    */
/* ZADANIE 2 - SORTOWANIE PRZEZ SCALANIE MERGE_SORT   */
/*                                                    */
/******************************************************/

// TESTY / DRIVER
    // float tab[10] = {1.0, 14.0, 9.0, 3.0, 8.0, 0.0, 15.0, 9.0, 6.0, 5.0};

    // std::cout << "Tablica nieposortowana: " << std::endl;
    // for( int i = 0; i < 10; i++)
    // {
    //     std::cout << tab[i] << " ";
    // }
    // std::cout << std::endl;

    // 10 000   ; 100 000 ;     500 000 ;   max z pliku
    
    std::random_device rd;
    std::mt19937 g(rd());

    // for (int i = 100; i < 10000; i+=100)
    // {
    //     std::cout << "Zaczynam działanie kapitanie\n";
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure2.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;


    //     std::shuffle(structure2.data(), structure2.data() + i, g);
    // }

    // for (int i = 100; i < 100000; i+=1000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure2.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane1 << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure2.data(), structure2.data() + i, g);

    // }

    for (int i = 100; i < 500000; i+=5000)
    {
        auto begin = std::chrono::high_resolution_clock::now();

        merge_sort(structure2.data(), 0, i);

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        dane2 << elapsed.count() << "\n";
        std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

        std::shuffle(structure2.data(), structure2.data() + i, g);

    }

    //     for (int i = 100; i < structure2.size(); i+=10000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure2.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane3 << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure2.data(), structure2.data() + i, g);

    // }



    // for (int i = 0; i < structure2.size(); i++)
    // {
    //     std::cout << structure2[i].first  << " " <<  structure2[i].second  << std::endl;
    // }

    // std::cout << "Tablica posortowana: " << std::endl;
    // for( int i = 0; i < 10; i++)
    // {
    //     std::cout << tab[i] << " ";
    // }
    // std::cout << std::endl;





/******************************************************/
/*                                                    */
/* ZADANIE 2 - SORTOWANIE SZYBKIE QUICKSORT           */
/*                                                    */
/******************************************************/

// TESTY / DRIVER
    // float tab[10] = {1.0, 14.0, 9.0, 3.0, 8.0, 0.0, 15.0, 9.0, 6.0, 5.0};

    // std::cout << "Tablica nieposortowana: " << std::endl;
    // for( int i = 0; i < 10; i++)
    // {
    //     std::cout << tab[i] << " ";
    // }
    // std::cout << std::endl;

    // quicksort(tab, 0, 9);

    // std::cout << "Tablica posortowana: " << std::endl;
    // for( int i = 0; i < 10; i++)
    // {
    //     std::cout << tab[i] << " ";
    // }
    // std::cout << std::endl;




}