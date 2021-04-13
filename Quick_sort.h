#pragma once
#ifndef QUICK_SORT
#define QUICK_SORT
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int  temp = *a;
    *a = *b;
    *b = temp;

}




int partition(int* arr, int  l, int r) {
    while (l < r) {
        //moving left index to righ
        for (; arr[l] <= arr[r] && l != r; l++);
        //swapping if it is needed
        swap(arr[l], arr[r]);
        //moving right index to left
        for (; arr[l] <= arr[r] && l != r; r--);
     
        swap(arr[l], arr[r]);
    }


        return r;
}

void quicksort(int* arr, int l, int r) {
    if (l <= r) {
        int pivot = partition(arr, l, r);
        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, r);
    }

}

/*int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
/* void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
   //     int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
      //  cout << "before partionioning" << endl;
     //   quicksort(arr, low, pi - 1);
      //  quicksort(arr, pi + 1, high);
        //cout << "after partionioning" << endl;
    //}
//}*/



#endif