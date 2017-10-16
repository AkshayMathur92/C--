//
//  HashTable.cpp
//  HashTable
//
//  Created by Akshay Mathur on 15/10/17.
//  Copyright © 2017 Akshay Mathur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int int_hash(int i){
    return i;
}

template <typename K,typename V, int (*F)(K)>
class HashTable {
    struct Node{
        K key;
        V value;
        Node* next;
        Node(K k, V v):key(k), value(v), next(nullptr){}
        Node(K k):key(k), value(V()), next(nullptr){}
    };
    vector<Node*> table = vector<Node*>(16,nullptr);
public:
    
    V operator[](K k)const {
        Node* itr = table[hash_func(k) & 15];
        while(itr != nullptr && itr -> key != k){
            itr = itr -> next;
        }
        if(itr == nullptr){
            Node *n = new Node(k);
            itr = table[hash_func(k) & 15];
            n -> next = itr;
            table[hash_func(k) & 15] = n;
        }
        return itr -> value;
    }
    V& operator[](K k) {
        Node* itr = table[F(k) & 15];
        while(itr != nullptr && itr -> key != k){
            itr = itr -> next;
        }
        if(itr){
            return itr -> value;
        }
        auto i = (new Node(k));
        if(table[F(k) & 15]){
            i -> next = table[F(k) & 15];
            table[F(k) & 15] = i;
        }
        else{
            table[F(k) & 15] = i;
        }
        return i -> value;
    }
    
};


int main(int argc, const char * argv[]) {
    HashTable<int, string, int_hash> ht;
    ht[1] = "one";
    ht[2] = "two";
    ht[16] = "sixteen";
    ht[17] = "seventeen";
    cout << ht[1] << endl;
    cout << ht[2] << endl;
    cout << ht[16] << endl;
    cout << ht[17] << endl;
    return 0;
}
