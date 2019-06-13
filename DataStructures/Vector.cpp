#include <iostream> 
#include <string> 
#include <exception>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <memory>

template <typename T> class Vector { 
	
	std::unique_ptr<T[]> mem;
	T* pbegin;
	T* pend;
	T* tail;
	
	void resize(int new_size){
		try{
		    std::unique_ptr<T[]> new_mem = std::unique_ptr<T[]>(new T[new_size]);
			auto new_pbegin = new_mem.get();
			std::copy(pbegin,pend,new_pbegin);
			tail = new_pbegin + new_size;
			pend = new_pbegin + size();
			std::swap(mem, new_mem);
			pbegin = new_pbegin;
		}
		catch(std::bad_alloc ex){
			throw ex;
		}
	}
	
public :
	Vector(int n){
		if (n <= 0)
			throw std::invalid_argument("value can only be a natural number");
		try{
		    mem = std::unique_ptr<T[]>(new T[n]);
		}
		catch (std::bad_alloc ex){
			throw ex;
		}
		pbegin = mem.get();
		pend = pbegin;
		tail = pbegin + n;
	}
	Vector():Vector(2){}

	~Vector(){
	}

	void push_back(T elm){
		if (pend == tail){
			expand();
		}
		*pend = elm;
		pend ++;
	}
	
	void pop_back(){
		pend--;
		if (pend < pbegin + (capacity() / 2)){
			shrink_to_fit();
		}
	}

	void insert(T elm, int n){
		if(n < 0 || n >= size())
			throw std::out_of_range("invalid index");
		if(pend == tail)
			expand();
		std::move(pbegin + n, pend, pbegin + n + 1);
		*(pbegin + n) = elm;
		pend ++;
	}

	int size(){
		return pend - pbegin;
	}

	int capacity(){
		return tail - pbegin;
	}

	bool empty(){
		return pend == pbegin;
	}

	void expand(){
	    resize(capacity() * 2);
	    std::cout << "EXPANDED" << std::endl;
	}
	
	void shrink_to_fit(){
	    resize(size());
	    std::cout << "SHRINKED" << std::endl;
	}

	T& operator[](int n){
		if(n < 0 || n >= size())
			throw std::out_of_range("Invalid Index");

		return *(pbegin + n);
	}

	T* begin(){
		return pbegin;
	}

	T* end(){
		return pend;
	}
	
	T& front(){
	    this->operator[](0);
	}
	
	T& back(){
	    this->operator[](size() - 1);
	}

};

int main(){
	Vector<int> vec;
	for(int i = 0; i < 50; i++){
		vec.push_back(i);
	}
	vec.insert(-1, 0);
	for(auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
	auto itr = std::find(vec.begin(), vec.end(), 28);
	if(itr != vec.end())
		std::cout << *itr << " found";
	std::cout << " Front " << vec.front() << " " << " Back " << vec.back() <<std::endl;
	for(int i = 0; i < 49; i++){
		vec.pop_back();
	}
	std::cout << std::endl;
	for(auto i : vec)
		std::cout << i << " ";
	return 0;
}
