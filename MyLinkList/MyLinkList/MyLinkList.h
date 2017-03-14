#pragma once
#include "LinkListElem.h"
#include <memory>
#include <iostream>

template <class T>
class MyLinkList
{
	std::shared_ptr<LinkListElem<T>> head;

public:
	MyLinkList() :head(nullptr){}
	~MyLinkList(){}

	void add(T elem){
		auto &new_elem = std::shared_ptr<LinkListElem<T>>(new LinkListElem<T>(elem));
		if (head){
			new_elem->next = head;
		}
		head = new_elem;
	}

	void traverse(){
		auto curr = head;
		while (curr){
			std::cout << curr->data << " ";
			curr = curr->next;
		}
	}
};

