#pragma once

template<typename T>
class I_binary_heap
{
public:
	virtual void inster(T value) = 0;
	virtual void erase(T value) = 0;
	virtual void heap_sort() = 0;
	virtual T get_max() = 0;
	virtual void print_heap() = 0;
};