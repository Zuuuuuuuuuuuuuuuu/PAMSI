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
    
    for (int i = 0; i < sub_array1; i++)          //  
    {
        left_array[i] = array[left + i];
    }
}


