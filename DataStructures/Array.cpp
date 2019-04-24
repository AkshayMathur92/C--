#pragma once
#include <iterator>
	
template<typename T, size_t C>
class Array
{
	T* data;
	size_t capacity;
	void validate(size_t n) {
		if (n >= capacity || n < 0) {
			throw std::invalid_argument("Out of bounds " + n);
		}
	}
public:
	Array() {
		capacity = C;
		data = new T[capacity];
	}
	virtual ~Array() {
		delete data;
	}
	T& operator[](size_t n) {
		validate(n);
		return data[n];
	}
	T* begin() {
		return data;
	}
	T* end() {
		return data + capacity;
	}
	void print() {
		for (T t : *this) {
			std::cout << t << " ";
		}
		std::cout << std::endl;
	}
};