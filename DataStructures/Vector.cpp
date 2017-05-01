#include <iostream> 
#include <string> 
#include <exception>
#include <stdexcept>
#include <iterator>
#include <algorithm>

template <typename T> class Vector { 
	
	T* pbegin;
	T* pend;
	T* tail;
	const float inc_factor = 0.8;
public :
	Vector(int n){
		if (n <= 0)
			throw std::invalid_argument("value can only be a natural number");
		try{
			pbegin = new T[n];
		}
		catch (std::bad_alloc ex){
			throw ex;
		}
		pend = pbegin;
		tail = pbegin + n;
	}
	Vector(){
		Vector(2);
	}

	~Vector(){
		delete pbegin;
	}

	void push_back(T elm){
		if (pend == tail){
			expand();
		}
		*pend = elm;
		pend ++;
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
		try{
			auto new_pbegin = new T[int(size() * (1 + inc_factor))];
			std::copy(pbegin,pend,new_pbegin);
			tail = new_pbegin + int(size() * (1 + inc_factor));
			pend = new_pbegin + size();
			delete pbegin;
			pbegin = new_pbegin;
		}
		catch(std::bad_alloc ex){
			throw ex;
		}
		// std::cout << "EXPANDED"<<std::endl;
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

};

int main(){
	Vector<int> vec(6);
	for(int i = 0; i < 50; i++){
		vec.push_back(i);
	}
	vec.insert(-1, 0);
	for(auto i : vec)
		std::cout << i << " ";
	auto itr = std::find(vec.begin(), vec.end(), 28);
	if(itr != vec.end())
		std::cout << *itr << " found";
	return 0;
}