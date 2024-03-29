#include "pch.h"
#include "include/binary_heap.h"

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec { 7,8,2,1,0,9,5 };
	binary_heap<int> heap(vec);

	heap.print_heap();

	heap.heap_sort();
	heap.print_heap();
}
