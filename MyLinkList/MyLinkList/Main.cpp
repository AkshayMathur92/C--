#include "MyLinkList.h"

int main(){

	MyLinkList<int> list;

	for (int i = 0; i < 32767; i++)
		list.add(i);
	list.traverse();
	return 0;
}