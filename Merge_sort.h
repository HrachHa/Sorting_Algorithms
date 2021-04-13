#pragma once
#ifndef MERGE_SORT
#define MERGE_SORT
#include <iostream>
using namespace std;



void  merge(int* arr, int l,int m, int high) {
//void merge(vector<int> arr ,int l, int m ,int high){
	//getting subarray sizes
	int first_array_size =m - l + 1;
	int second_array_size = high -m;

	//creating sub arrays
	int* first_array = new int[first_array_size];
	int* second_array = new int[second_array_size];
	
	//filling first sub array
	for (int i = 0; i < first_array_size; i++) {
		first_array[i] = arr[l + i];
	}
	
	//filling second sub array
	for (int i = 0; i < second_array_size; i++) {
		second_array[i] = arr[m + 1 + i];
	}

	// setting index for first array
	int first_index = 0;
	//setting index for second array
	int second_index = 0;
	//index of merged sub array
	int output  = l;

	//merging elements in merged subbaray
	for (output ; first_index < first_array_size && second_index < second_array_size; output++) {
		if (first_array[first_index] <= second_array[second_index]) {
			arr[output] = first_array[first_index];
			first_index++;
		}
		else {
			arr[output] = second_array[second_index];
			second_index++;
		}
	}
	//putting elements which left in subbarays
	for (int i = first_index; i < first_array_size; i++,output++) {
		arr[output] = first_array[i];
	}

	for (int i = second_index; i < second_array_size; i++,output++) {
		arr[output] = second_array[i];
	}

	delete[] first_array;
	delete[] second_array;

}

void mergeSort(int* arr, int low, int high) {
	if (low < high) {
		int middle = (low + high - 1) / 2;

		mergeSort(arr, low, middle);
		mergeSort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	
	}

	
}
#endif MERGE_SORT// !MERGE_SORT
