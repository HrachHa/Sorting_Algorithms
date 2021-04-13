#include <iostream>
#include "Generate_data.h"
#include "Quick_sort.h"
#include <chrono>
#include <vector>
#include <sstream>
#include "Heap_sort.h"
#include "Merge_sort.h"
using namespace std::chrono;




int main() {
	




	
	int tests_count, begining_size, starting_num;
	cout << "Please input tests_count,begining size of the vector and starting number" << endl;
	cin >> tests_count >> begining_size >> starting_num;

	
	int array_size;
	string result_file;
	int itterations;
	cout << "Please input results file name with the extension csv" << endl;
	cin >> result_file;
	cout << "Please input the size where you want to stop your tests " << endl;
	cin >> array_size;
	cout << "Please input the itteration count" << endl;
	cin >> itterations;

	ofstream  for_result;
	for_result.open(result_file);
	string desc = "size , quick , merge , heap , quick_sorted , merge_sorted , heap_sorted ";
	for_result << desc << endl;

	random_device rd;
	mt19937 gen(rd());

	for (int i = 0; i < tests_count; i++) {
			 int st_num = starting_num;
			 
			
			 chrono::nanoseconds total_quick(0);
			 chrono::nanoseconds total_merge(0);
			 chrono::nanoseconds total_heap(0);
			 chrono::nanoseconds total_worst_quick(0);
			 chrono::nanoseconds total_worst_merge(0);
			 chrono::nanoseconds total_worst_heap(0);
			 
			 if (begining_size > array_size) return 0;

			 for_result << begining_size << ",   ";


			uniform_int_distribution<int> dist(0, st_num);
			for (int k = 0; k < itterations; k++) {
				int* quick_test = new int[begining_size];
				int* merge_test = new int[begining_size];
				int* heap_test = new int[begining_size];
				for (int j = 0; j < begining_size; j++) {
					quick_test[j] = dist(gen);
					merge_test[j] = dist(gen);
					heap_test[j] = dist(gen) ;
				}
				starting_num += 20;
			





				//average case for Quick sort

				auto start_ = chrono::steady_clock::now();
				quicksort(quick_test, 0, begining_size - 1);
				auto end = chrono::steady_clock::now();
				chrono::nanoseconds time_taken(end - start_);
				total_quick += time_taken;
				



				//average  case for merge case
				auto start_merge = chrono::steady_clock::now();
				mergeSort(merge_test, 0, begining_size - 1);
				auto end_merge = chrono::steady_clock::now();
				chrono::nanoseconds time_taken_merge(end_merge - start_merge);
				total_merge += time_taken_merge;
				
				//average case for heap sort
				Heap h(heap_test, begining_size);
				auto start_heap = chrono::steady_clock::now();
				int* sorted_h = heap_sort(h);
				auto end_heap = chrono::steady_clock::now();
				chrono::nanoseconds time_taken_heap(end_heap - start_heap);
				total_heap += time_taken_heap;
				
				//worst case for quick sort 

				auto start_1 = chrono::steady_clock::now();
				quicksort(quick_test, 0, begining_size - 1);
				auto end_1 = chrono::steady_clock::now();
				chrono::nanoseconds time_taken_2(end_1 - start_1);
				total_worst_quick += time_taken_2;
				
				//worst case for merge sort
				auto start_merge_sorted = chrono::steady_clock::now();
				mergeSort(merge_test, 0, begining_size - 1);
				auto end_merge_sorted = chrono::steady_clock::now();
				chrono::nanoseconds time_taken_sorted_merge(end_merge_sorted - start_merge_sorted);
				total_worst_merge += time_taken_sorted_merge;
				
				//worst case for heap sort
				Heap sorted_heap(sorted_h, begining_size);
				auto start_heap_sorted = chrono::steady_clock::now();
				int* worst_heap = heap_sort(sorted_heap);
				auto end_heap_sorted = chrono::steady_clock::now();
				chrono::nanoseconds time_taken_heap_sorted(end_heap_sorted - start_heap_sorted);
				total_worst_heap += time_taken_heap_sorted;
				
				delete worst_heap;
				delete[] quick_test;
				delete[] merge_test;
				delete[] heap_test;
			}
			for_result << total_quick.count()/itterations << ",  ";
			for_result << total_merge.count() / itterations << ", ";
			for_result << total_heap.count() / itterations << ", ";
			for_result << total_worst_quick.count() / itterations << ", ";
			for_result << total_worst_merge.count() /itterations << ",  ";
			for_result << total_worst_heap.count() / itterations << ",  ";
			for_result << endl;
 
			 if (begining_size < 100) begining_size *= 10;
			 else if (begining_size < 1000) begining_size += 400;
			 else if (begining_size < 10000) begining_size += 3000;
			 else begining_size += 10000;
		}

		
	}
	




//}