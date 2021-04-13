#pragma once
#ifndef HEAP_SORT
#define HEAP_SORT

inline void swap(int* a, int* b);

class Heap {
private:
	int* arr;
	int size;
	int* heap;
	int size_now;
public:
	Heap(int *, int) ;
	int size_of_heap();
	int parent(int child);
	int left_child(int parent);
	int right_child(int parent);
	int extract_max();
	void max_heap(int i);
	void fill_heap(); 
	void build_heap();
	void print_created();
	friend int* heap_sort(Heap a);
};



#endif HEAP_SORT // !HEAP_SORT
