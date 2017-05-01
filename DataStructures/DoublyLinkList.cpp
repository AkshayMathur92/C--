#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T> 
class DoublyLinkList{

	template <typename N> class Node{
public:
		N data;
		Node<N>* prev;
		Node<N>* next;
		Node(N data):data(data),prev(nullptr),next(nullptr){}
	};

	Node<T>* head;
	Node<T>* tail;
	int _size;
public:
	DoublyLinkList():head(nullptr),tail(nullptr),_size(0){}
	~DoublyLinkList(){
		auto curr = head;
		while(curr){
			head = head -> next;
			delete curr;
			curr = head;
		}
	}


	template <typename N> class iterator: public std::iterator<std::forward_iterator_tag, T>{

		Node<N>* node;
	public:
		iterator(Node<N>* node):node(node){}
		iterator operator++(){
			node = node -> next;
			return *this;
		}
		iterator operator++(int){
			return operator++();
		}
		iterator operator--(){
			node = node -> prev;
			return *this;
		}
		iterator operator--(int){
			return operator--();
		}
		bool operator==(iterator &i){
			if(node == nullptr && i.node == nullptr) return true;
			if(node == nullptr || i.node == nullptr) return false;
			return (i.node->next == node -> next && i.node->prev == node->prev && i.node->data == node->data);
		}
		bool operator!=(const iterator &ni){
            if (node == nullptr && ni.node == nullptr)
                return false;
            else
                return true;
        }
		N& operator*(){
			return node->data;
		}
	};

	void add_begin(T data){
		auto new_node = head;
		try{
			 new_node = new Node<T>(data);
		}catch (std::bad_alloc ex){
			throw ex;
		}
		if(head == nullptr){
			head = new_node;
			tail = head;
			_size++;
			return;
		}
		new_node->next = head;
		head -> prev = new_node;
		head = new_node;
		_size++;
	}

	void add_end(T data){
		auto new_node = head;
		try{
			 new_node = new Node<T>(data);
		}catch (std::bad_alloc ex){
			throw ex;
		}
		if(head == nullptr){
			head = new_node;
			tail = head;
			_size++;
			return;
		}
		new_node -> prev = tail;
		tail->next = new_node;
		tail = new_node;
		_size++;
	}

	int size(){
		return _size;
	}

	void insert(T data, int n){
		if(n < 0 || n >= _size)
			throw std::out_of_range("Invalid Position");
		if(n == 0){
			add_begin(data);
			return;
		}
		else if(n == _size -1){
			add_end(data);
			return;
		}
		auto new_node = new Node<T>(data);
		auto curr = head;
		if(n <= _size/2){
			for(int i = 0; i < n - 1 ; i++)
				curr = curr -> next;
		}
		else{
			curr = tail;
			for(int i = _size - n; i > 0 ; i--)
				curr = curr -> prev;
		}
		new_node -> next = curr -> next;
		new_node -> prev = curr;
		curr -> next -> prev = new_node;
		curr -> next = new_node;
		_size++;
	}

	iterator<T> get(int n){
		if(n < 0 || n >= _size)
			throw std::out_of_range("Invalid Position");

		if(n <= _size/2){
			auto curr = head;
			for(int i = 0; i < n; i++){
				curr = curr -> next;
			}
			return iterator<T>(curr);
		}
		else{
			auto curr = tail;
			for(int i = n; i >=0 ; i--){
				curr = curr -> prev;
			}
			return iterator<T>(curr);
		}
	}

	iterator<T> begin(){
		return iterator<T>(head);
	}
	iterator<T> end(){
		return iterator<T>(nullptr);
	}

};


int main(){
	DoublyLinkList<int> dll;
	for(int i = 0 ;i< 10 ; i ++)
		dll.add_begin(i);
	dll.add_end(-1);
	dll.insert(23, 7);
	dll.insert(10, 0);
	std::cout << dll.size() << std::endl;
	dll.insert(-2, 12);
	for(auto i : dll)
		std::cout << i << " ";
	std::cout << *dll.get(5) << std::endl;
	auto itr = find(dll.begin(), dll.end(), 3);
	if(itr != dll.end())
		std::cout << std::endl << *itr << " found";
}