#pragma once

#include "I_binary_heap.h"

#include <vector>

template<typename T>
class binary_heap : public I_binary_heap<T>
{
public:
	binary_heap() = default;
	binary_heap(std::vector<T> vec);

	void inster(T value);
	void erase(T value);
	void heap_sort();

	T get_max();

	void print_heap(); // for debug
private:
	void build_heap();
	void sift_down(size_t idx);
	void sift_down(size_t begin, size_t end);
	void sift_up(size_t idx);
	T extract_max();
private:
	std::vector<T> m_data;
};

#include "binary_heap_impl.h"