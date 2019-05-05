#pragma once

#include "binary_heap.h"

template<typename T>
binary_heap<T>::binary_heap(std::vector<T> vec)
	: m_data(vec)
{
	build_heap();
}

template<typename T>
void binary_heap<T>::build_heap()
{
	int idx = (m_data.size() / 2 - 1);
	while (idx >= 0)
	{
		sift_down(idx--);
	}
}

template<typename T>
void binary_heap<T>::sift_down(size_t idx)
{
	size_t left = 2 * idx + 1;
	size_t right = 2 * idx + 2;
	size_t largest = idx;

	if (left < m_data.size() && m_data[idx] < m_data[left])
		largest = left;
	if (right < m_data.size() && m_data[largest] < m_data[right])
		largest = right;

	if (largest != idx)
	{
		std::swap(m_data[largest], m_data[idx]);
		sift_down(largest);
	}
}

template<typename T>
void binary_heap<T>::sift_down(size_t begin, size_t end)
{
	size_t left = 2 * begin + 1;
	size_t right = 2 * begin + 2;
	size_t largest = begin;

	if (left < end && m_data[begin] < m_data[left])
		largest = left;
	if (right < end && m_data[largest] < m_data[right])
		largest = right;

	if (largest != begin)
	{
		std::swap(m_data[largest], m_data[begin]);
		sift_down(largest, end);
	}
}

template<typename T>
void binary_heap<T>::sift_up(size_t idx)
{
	while (idx > 0)
	{
		size_t parent = (idx - 1) / 2;
		if (m_data[parent] < m_data[idx])
			std::swap(m_data[parent], m_data[idx--]);
		else return;
		idx = parent;
	}
}

template<typename T>
void binary_heap<T>::inster(T value)
{
	m_data.push_back(value);
	sift_up(m_data.size()-1);
}

template<typename T>
void binary_heap<T>::erase(T value)
{
	size_t idx = std::distance(m_data.begin(), std::find(m_data.begin(), m_data.end(), value));
	std::swap(m_data[idx], m_data[m_data.size() - 1]);
	m_data.erase(m_data.end()-1);
	sift_down(idx);
}

template<typename T>
T binary_heap<T>::get_max()
{
	return m_data[0];
}

template<typename T>
T binary_heap<T>::extract_max()
{
	T max = m_data[0];
	std::swap(m_data[0], (m_data.size() - 1));
	m_data.erase(m_data.size() - 1);
	sift_down(0);
	return max;
}

template<typename T>
void binary_heap<T>::heap_sort()
{
	size_t heap_size = m_data.size() - 1;
	while (heap_size > 0)
	{
		std::swap(m_data[0], m_data[heap_size--]);
		sift_down(0, heap_size);
	}
}

template<typename T>
void binary_heap<T>::print_heap()
{
	for (const auto& it : m_data)
	{
		std::cout << it << std::ends;
	}
	std::cout << std::endl;
}