/******************************************************************************

                            Array Implementation and Analysis

*******************************************************************************/
#include <memory>
#include <iostream>

template<typename T, size_t C>
class Array
{
	std::unique_ptr<T[]> data;
	size_t capacity;
	void validate(size_t n) {
		if (n >= capacity || n < 0) {
			throw std::invalid_argument("Out of bounds " + n);
		}
	}
public:
	Array() {
		capacity = C;
		data = std::unique_ptr<T[]>(new T[capacity]);
	}
	T& operator[](size_t n) {
		validate(n);
		return data.get()[n];
	}
	T* begin() {
		return data.get();
	}
	T* end() {
		return data.get() + capacity;
	}
	void print() {
		for (T t : *this) {
			std::cout << t << " ";
		}
		std::cout << std::endl;
	}
};
int main ()
{
  Array < int, 5 > myarray;
  for (int i = 0; i < 5; i++)
    {
      myarray[i] = i;
    }
  myarray.print ();
  
  std::cout << sizeof(myarray) << std::endl;
  
  Array<Array<int,5>,5> nested_array;
  for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
        {
          nested_array[i][j] = i * 5 + j;
        }
    }

    for(auto &darr : nested_array){
        darr.print();
    }
    
    for(auto &darr : nested_array){
        for(int &i : darr){
            std::cout << &i << " ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
