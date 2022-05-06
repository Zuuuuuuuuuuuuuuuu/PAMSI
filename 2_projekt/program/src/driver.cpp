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
        right_array[i] = array[middle + 1 + i];
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

void quicksort(float array[], int left, int right)
{
	if(right <= left) return;
	
	int i = left - 1;
    int j = right + 1; 
    int pivot = array[(left+right)/2]; 
	
	while(1)
    {
		while(pivot>array[++i]);
		while(pivot<array[--j]);
		
		
		if( i <= j)
			std::swap(array[i],array[j]);
		else
			break;
	}

	if(j > left)
	    quicksort(array, left, j);
	if(i < right)
	    quicksort(array, i, right);
}

/******************************************************/
/*                                                    */
/*  - SORTOWANIE  - funkcje INTROSORT                 */
/*                                                    */
/******************************************************/

void heapify(float array[], int n, int i)   // n to size ; i to index w tablicy
{
    int largest = i;        // najwiekszy jako ojciec
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
   
    if (l < n && array[l] > array[largest])
        largest = l;
 
 
    if (r < n && array[r] > array[largest])
        largest = r;
 
   
    if (largest != i) 
    {
       std::swap(array[i], array[largest]);
       heapify(array, n, largest);
    }
}

void heap_sort(float array[], int n)
{    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    
    for (int i = n - 1; i > 0; i--) 
    {
        std :: swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}


void insertion_sort (float array[], int N)
{
    int i, j;
    float temp;
    for (i=1; i<N; ++i)
    {
        temp=array[i];
        for (j=i; j>0 && temp<array[j-1]; --j)
          array[j]=array[j-1];
        array[j]=temp;
    }
}


int partition (float data[], int left , int right )
{
    int pivot = data[right];
    int temp;
    int i = left;
    for (int j = left ; j < right; ++j)
    {
        if (data[j] <= pivot)
        {
            std::swap(data[j], data[i]);
            i++;
        }
    }

    data[right] = data[i];
    data[i] = pivot;

    return i;
}


void intro_sort(float array[] , int size)
{
    int partition_size = partition(array , 0, size - 1);
        if ( partition_size < 16)
        {
            insertion_sort(array , size );
        }
        else if (partition_size > (2 * std :: log( size )))
        {
            heap_sort(array, size );
        }
        else
        {
            quicksort(array, 0, size -1);
        }
}


float arithmetic_mean(std::vector<float> structure3, int j)
    {
        float srednia=0;
        for (int i = 0; i < j; i++)
        {
            srednia += structure3[i];
        }

        return srednia/j; 
    }

float mediana(std::vector<float> structure3, int j)
    {
        float k=0;
        if (j%2 == 0)   //jest parzysta liczba elementow
        {
            return structure3[j/2];
        }
        else 
        {
            k = ( j/2 + j/2+1 ) / 2;
            return k; 
        }
    }


int main()
{

/******************************************************/
/*                                                    */
/*          ZADANIE 1 - PRZESZUKIWANIE PLIKU          */
/*                                                    */
/******************************************************/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11 usuniecie pierwszego wiersza

   // file plik;
    std::fstream only_ratings_file("plik_z_danymi_tylko_rating.txt", std::ios::in);
    // std::fstream dane("przefiltrowane_dane_10tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane1("przefiltrowane_dane_100tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane2("przefiltrowane_dane_500tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane3("przefiltrowane_dane_max.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane_quick("quick_przefiltrowane_dane_10tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane1_quick("quick_przefiltrowane_dane_100tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane2_quick("quick_przefiltrowane_dane_500tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane3_quick("quick_przefiltrowane_dane_max.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane_intro("intro_przefiltrowane_dane_10tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane1_intro("intro_przefiltrowane_dane_100tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane2_intro("intro_przefiltrowane_dane_500tys.txt", std::ios::out);    // plik do zapisu czasu
    // std::fstream dane3_intro("intro_przefiltrowane_dane_max.txt", std::ios::out);    // plik do zapisu czasu



    // std::string title;
    // std::string rating;
    // std::vector<std::pair<std::string, std::string>> structure;

    // plik.open_input_file("projekt2_dane.csv");


    // while(true)
    // {
    //     plik.read_file(title, rating);
    //     structure.push_back( std::make_pair (title, rating) );  // wpisywanie pary do wektora
    //     if (plik.end_of_file()) 
    //     {
    //         break;
    //     }
    // }

    // plik.close_input_file();

    // // pętla przeszukiwania pustych pól w vectorze w rating
    // for (int i = 0; i< structure.size(); ++i)
    // {
    //     if ( structure[i].second.empty() )      // znalezienie pustego pola rating
    //     {
    //         structure.erase(structure.begin() + i--);
    //     }
    // }

    // for (int i = 0; i < structure.size(); ++i)
    // {
    //     only_ratings_file << structure[i].second << "\n";
    // }


    // auto begin = std::chrono::high_resolution_clock::now();
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // dane << elapsed.count() << "\n";
    // std::cout << "\nCzas: " << elapsed.count() << std::endl;


    // konwersja string na float
    // std::vector<std::pair<std::string, float>> structure2;
    // for (int i = 0; i < structure.size(); ++i)
    // {
    //     float rating = std::stof(structure[i].second);
    //     structure2.push_back( std::make_pair (title, rating) );
    // }

    std::vector <float> structure3;
    std::string tmp;
    
    while (true)
    {
        if (only_ratings_file.eof())
        {
            break;
        }
        std::getline(only_ratings_file, tmp);
        structure3.push_back(std::stof(tmp));
    }

    // for (int i = 0; i < structure3.size(); ++i)
    // {
    //     float rating = std::stof(structure[i].second);
    //     structure3.push_back(rating);
    // }




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
    
    // std::random_device rd;
    // std::mt19937 g(rd());

    // std::cout << "Zaczynam działanie kapitanie dla 10tys\n";

    
    // ŚREDNIA I MEDIANA


    // merge_sort(structure3.data(), 0, 10000);
    // float aa = arithmetic_mean(structure3, 10000);
    // float bb = mediana(structure3, 10000);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   merge_sort 10 000 \n";

    // merge_sort(structure3.data(), 0, 100000);
    // aa = arithmetic_mean(structure3, 100000);
    // bb = mediana(structure3, 100000);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   merge_sort 100 000 \n";

    // merge_sort(structure3.data(), 0, 500000);
    // aa = arithmetic_mean(structure3, 500000);
    // bb = mediana(structure3, 500000);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   merge_sort 500 000 \n";

    // merge_sort(structure3.data(), 0, structure3.size()-1);
    // aa = arithmetic_mean(structure3, structure3.size()-1);
    // bb = mediana(structure3, structure3.size()-1);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   merge_sort max \n";

    

    quicksort(structure3.data(), 0, 10000);
    float aa = arithmetic_mean(structure3, 10000);
    float bb = mediana(structure3, 10000);
    std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   quicksort 10 000 \n";

    quicksort(structure3.data(), 0, 100000);
    aa = arithmetic_mean(structure3, 100000);
    bb = mediana(structure3, 100000);
    std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   quicksort 100 000 \n";

    quicksort(structure3.data(), 0, 500000);
    aa = arithmetic_mean(structure3, 500000);
    bb = mediana(structure3, 500000);
    std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   quicksort 500 000 \n";

    quicksort(structure3.data(), 0, structure3.size()-1);
    aa = arithmetic_mean(structure3, structure3.size()-1);
    bb = mediana(structure3, structure3.size()-1);
    std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   quicksort max \n";



    // intro_sort(structure3.data(), 10000);
    // aa = arithmetic_mean(structure3, 10000);
    // bb = mediana(structure3, 10000);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   intro_sort 10 000 \n";

    // intro_sort(structure3.data(), 100000);
    // aa = arithmetic_mean(structure3, 100000);
    // bb = mediana(structure3, 100000);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "    intro_sort 100 000 \n";

    // intro_sort(structure3.data(), 500000);
    // aa = arithmetic_mean(structure3, 500000);
    // bb = mediana(structure3, 500000);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   intro_sort 500 000 \n";

    // intro_sort(structure3.data(), structure3.size()-1);
    // aa = arithmetic_mean(structure3, structure3.size()-1);
    // bb = mediana(structure3, structure3.size()-1);
    // std::cout << "srednia: " << aa << "   " << "mediana: " << bb << "   intro_sort max \n";
    // std :: cout << "Kocham Zuzuie" << '\n';
    // std :: sort(structure3.begin(),structure3.begin() + 10000);
    // aa =  std :: accumulate(structure3.begin(), structure3.begin() + 10000, 0);
    // std :: cout << aa / 10000 << '\n';

    // std :: sort(structure3.begin(),structure3.begin() + 100000);
    // aa =  std :: accumulate(structure3.begin(), structure3.begin() + 100000, 0);
    // std :: cout << aa / 100000 << '\n';

    // std :: sort(structure3.begin(),structure3.begin() + 500000);
    // aa =  std :: accumulate(structure3.begin(), structure3.begin() + 500000, 0);
    // std :: cout << aa / 500000 << '\n';
    // std :: cout << "Kocham Zuzuie <3" << '\n';

    // std :: sort(structure3.begin(),structure3.end());
    // aa =  std :: accumulate(structure3.begin(), structure3.begin() + 10000, 0);
    // std :: cout << aa / 10000 << '\n';
    // aa =  std :: accumulate(structure3.begin(), structure3.begin() + 100000, 0);
    // std :: cout << aa / 100000 << '\n';
    // aa =  std :: accumulate(structure3.begin(), structure3.begin() + 500000, 0);
    // std :: cout << aa / 500000 << '\n';

    // aa =  std :: accumulate(structure3.begin(), structure3.end(), 0);
    // std :: cout << aa / structure3.size() << '\n';







    // for (int i = 100; i < 10000; i+=100)
    // {

    //     merge_sort(structure3.data(), 0, i);

    //     aut elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);
    // }









    // for (int i = 100; i < 10000; i+=100)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);
    // }

    // std::cout << "Zaczynam działanie kapitanie dla 100tys\n";

    // for (int i = 100; i < 100000; i+=1000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane1 << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }

    // std::cout << "Zaczynam działanie kapitanie dla 500tys\n";

    // for (int i = 100; i < 500000; i+=5000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane2 << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }

    // std::cout << "Zaczynam działanie kapitanie dla maxa. Zapnij pasy.\n";

    //     for (int i = 100; i < structure3.size(); i+=10000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     merge_sort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane3 << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

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

    // std::random_device rd;
    // std::mt19937 g(rd());

    // std::cout << "Zaczynam działanie kapitanie dla 10tys\n";


    // for (int i = 100; i < 10000; i+=100)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     quicksort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane_quick << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);
    // }

    // std::cout << "Zaczynam działanie kapitanie dla 100tys\n";

    // for (int i = 100; i < 100000; i+=1000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     quicksort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane1_quick << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }

    // std::cout << "Zaczynam działanie kapitanie dla 500tys\n";

    // for (int i = 100; i < 500000; i+=5000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     quicksort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane2_quick << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }

    // std::cout << "Zaczynam działanie kapitanie dla maxa. Zapnij pasy.\n";

    //     for (int i = 100; i < structure3.size(); i+=10000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     quicksort(structure3.data(), 0, i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane3_quick << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }



/******************************************************/
/*                                                    */
/* ZADANIE 2 - SORTOWANIE INTROSORT                   */
/*                                                    */
/******************************************************/


    // std::random_device rd;
    // std::mt19937 g(rd());

    // std::cout << "Zaczynam działanie kapitanie dla 10tys\n";


    // for (int i = 100; i < 10000; i+=100)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     intro_sort(structure3.data(), i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane_intro << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);
    // }

    // std::cout << "Zaczynam działanie kapitanie dla 100tys\n";

    // for (int i = 100; i < 100000; i+=1000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     intro_sort(structure3.data(), i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane1_intro << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }

    // std::cout << "Zaczynam działanie kapitanie dla 500tys\n";

    // for (int i = 100; i < 500000; i+=5000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     intro_sort(structure3.data(), i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane2_intro << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }

    // std::cout << "Zaczynam działanie kapitanie dla maxa. Zapnij pasy.\n";

    //     for (int i = 100; i < structure3.size(); i+=10000)
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();

    //     intro_sort(structure3.data(), i);

    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //     dane3_intro << elapsed.count() << "\n";
    //     std::cout << "\nCzas: " << elapsed.count() << " dla i: " << i << std::endl;

    //     std::shuffle(structure3.data(), structure3.data() + i, g);

    // }



}