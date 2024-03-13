#include <iostream> 
#include <cmath>
#include<algorithm>
#include <string>
#include <stdlib.h>

// const int x;          // x is a constant data variable
// int const x;          // x is a constant data variable

// const int* x;         // x is a non-constant pointer to constant data
// int const* x;         // x is a non-constant pointer to constant data 

// int*const x;          // x is a constant pointer to non-constant data

// const int*const x;    // x is a constant pointer to constant data

// Пузырьком
unsigned bubble_sort(int arr[], unsigned const begin, unsigned const end)
    {
        bool sorted = false; 
        while(!sorted)
            {
                sorted = true;
                for(int idx = begin; idx != end - 1; idx++)
                    if(arr[idx + 1] < arr[idx])
                    {
                        std::swap(arr[idx + 1], arr[idx]);
                        sorted = false;
                    }
            }
    }

// ВЫБОР
// ищем наименьший и в конец отсортированной части 
unsigned choice_sort(int arr[], unsigned const begin, unsigned const end)
{
    for(unsigned sorted = begin; sorted != end - 1; sorted++)
{
        for(int idx = sorted + 1; idx <= end - 1; idx++)
            {
                if(arr[sorted] > arr[idx])
                std::swap(arr[idx], arr[sorted]);
            }
}
}
   
// ВСТАВКИ
unsigned insert_sort(int arr[], unsigned const begin, unsigned const end)
{
    for(unsigned sorted = begin; sorted != end - 1; sorted++)
        for (int idx = sorted + 1; idx >= 0; --idx )
        if (arr[idx] > arr[idx + 1])
        std::swap(arr[idx], arr[idx + 1]);
}



// БЫСТРАЯ
unsigned partition_by_number(int data[], unsigned l_idx, unsigned r_idx, unsigned pivot)
{
    while(true)
    {
    while (data[l_idx] < pivot) ++l_idx;
    while (pivot < data[r_idx]) --r_idx;
        if (r_idx <= l_idx)
        return r_idx;
        std::swap(data[l_idx++], data[r_idx--]);
    }
        
    return r_idx;
}

// СЛИЯНИЯ (НЕ ИСПОЛЬЗУЯ ПАМЯТЬ)

unsigned array_merge(int from[], int to[], unsigned l_idx, unsigned split_idx, unsigned r_idx) 
{
unsigned left_run = l_idx, right_run = split_idx, to_run = l_idx;
while(left_run != split_idx && right_run != r_idx)
    to[to_run++] = from[left_run] < from[right_run] ? from[left_run++] : from[right_run++];

while(left_run != split_idx)
    to[to_run++] = from[left_run++];

while(right_run != r_idx)
    to[to_run++] = from[right_run++];
}




unsigned printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        std::cout << arr[i] << " "; 
    std::cout << std::endl; 
} 
  


int main()
{
    // std::cin >> n;
    int m[] = {5, 4, 1, 2, 8};
    array_merge(m, 0, 5);
    std::cout << printArray(m, 5);
    return 0;
}