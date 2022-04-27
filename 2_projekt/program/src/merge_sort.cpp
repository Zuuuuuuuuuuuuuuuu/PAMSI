/* SORTOWANIE PRZEZ SCALANIE */ 

#pragma once;
#include <iostream>

void merge(float array[], int left, int middle, int right)    // funkcja do scalania sub-tablic
{
    // podział tablicy na dwie części
    int sub_array1 = middle - left + 1;           // liczba elementów do pierwszej i drugiej sub-tablicy
    int sub_array2 = right - middle;

    float *left_array = new float[sub_array1];    // tworzenie nowych dynamicznych sub-tablic o zadanej liczbie elementów
    float *right_array = new float[sub_array2];
    
    for (int i = 0; i < sub_array1; i++)          //  wpisywanie odpowiednich elementów z podstawowej tablicy array do lewej sub-tablicy
    {
        left_array[i] = array[left + i];
    }
    
    for (int i = 0; i < sub_array2; i++)          //  wpisywanie odpowiednich elementów z podstawowej tablicy array do prawej sub-tablicy
    {
        right_array[i] = array[right - i];        // mid + 1 + i
    }

    int index_sub_array1 = 0;                     // pierwsze indeksy sub-tablic 
    int index_sub_array2 = 0;
    int index_merged_arrays = left;               // pierwszy indeks scalonej tablicy --> tak, żeby nie zepsuć całej wejściowej tablicy, jeśli do sortowania będzie brana jej część

    // sortowanie --> wkładanie odpowiednich elementów do wyjściowej tablicy
    while (index_sub_array1 < sub_array1 && index_sub_array2 < sub_array2)          // dopóki w obydwu sub-tablicach coś jest
    {
        if (left_array[index_sub_array1] <= right_array[index_sub_array2] )         // jeżeli dany element lewej tablicy jest mniejszy ...
        {
            array[index_merged_arrays] = left_array[index_sub_array1];              // przypisanie do tablicy wyjściowej mniejszego elementu
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

void merge_sort(float array[], int const begin, int const end)                      // funkcja do sortowania przez scalanie
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