#include "Heap_sort.h"
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;

}

Heap::Heap(int* make_heap, int make_heap_size) : arr(make_heap), size(make_heap_size), heap(new int[make_heap_size]) {
	size_now = 0;
	fill_heap();
	build_heap();

	}
int Heap::size_of_heap()
{
	return size;
}
int Heap::parent(int child)
{
	 return (child - 1) / 2;
}

int Heap::left_child(int parent)
{
	return 2 * parent + 1;
}

int Heap::right_child(int parent)
{
	return 2 * parent + 2;
}

int Heap::extract_max()
{
	if (size == 1) {
		size--;
		return heap[0];
	}

		
		int maximum_element = heap[0];
		heap[0] = heap[size - 1];
		size--;
		max_heap(0);
	

		return maximum_element;
}

void Heap::max_heap(int i)
{

	int left = left_child(i);
	int right = right_child(i);
	int biggest = i;
	if (left<size && heap[left]>heap[i] && heap[left] > heap[right]) {
		biggest = left;
	}
	else if (right<size && heap[right]>heap[i]) {
		biggest = right;
	}
	if (biggest != i) {
		int temp = heap[i];
		heap[i] = heap[biggest];
		heap[biggest] = temp;
		max_heap(biggest);
	}
	
}


void Heap::fill_heap()
{
	for (int i = 0; i < size; i++) {
		heap[i] = arr[i];
	}
}

void Heap::build_heap()
{
	for (int i = size-1; i >= 0; i--) {
		max_heap(i);
	}
}

			
		
void Heap::print_created()
{
	for (int i = 0; i < size; i++) cout << heap[i] << endl;
}

int* heap_sort(Heap h)
{
	//getting  size and sorted array after extracting max and putting in the end of sorted array
	int size = h.size_of_heap();

	int *sorted = h.heap;
	for (int i = size; i > 0; i--) {
		int val = h.extract_max();
		sorted[i - 1] = val;
	}
	return sorted;
}
