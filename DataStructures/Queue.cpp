//
//  Queue.cpp
//  LinkList
//
//  Created by Akshay Mathur on 16/10/17.
//  Copyright © 2017 Akshay Mathur. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


template<typename T>
class Queue{
    struct Node{
        T element;
        Node* left;
        Node* right;
        Node(T t):element(t), left(nullptr), right(nullptr){}
    };
    Node* head, *tail;
public:
    Queue():head(nullptr),tail(nullptr){}
    void push(T e){
        if(head == nullptr){
            head = new Node(e);
            tail = head;
            return;
        }
        auto temp = new Node(e);
        temp -> right = head;
        head -> left = temp;
        head = temp;
    }
    
    void pop(){
        if(head == tail){
            delete tail;
            head = tail = nullptr;
            return;
        }
        auto temp = tail;
        tail = tail -> left;
        delete temp;
    }
    T peek(){
        if(tail != nullptr)
            return tail -> element;
        return nullptr;
    }
    
    bool empty(){
        return head == nullptr;
    }
};

int main() {
    
    Queue<string> Q;
    Q.push("hello");
    Q.push("world");
    while(!Q.empty()){
        cout << Q.peek() << " " ;
        Q.pop();
    }
    return 0;
}

