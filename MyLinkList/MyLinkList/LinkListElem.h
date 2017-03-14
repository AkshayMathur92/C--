#pragma once
#include<memory>

template <typename T>
class LinkListElem
{
public:
	std::shared_ptr<LinkListElem<T>> next;
	T data;
	LinkListElem(T elem) :data(elem), next(nullptr){}
	~LinkListElem(){}
};

