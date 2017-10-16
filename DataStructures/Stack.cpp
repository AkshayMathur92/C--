//
//  Stack.cpp
//  LinkList
//
//  Created by Akshay Mathur on 16/10/17.
//  Copyright © 2017 Akshay Mathur. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
    struct Node{
        T element;
        Node* next;
        Node(T e):element(e), next(nullptr){}
    };
    Node* tp;
public :
    Stack():tp(nullptr){}
    void push(T ele){
        Node *n = new Node(ele);
        n -> next = tp;
        tp = n;
    }
    
    T top(){
        return tp -> element;
    }
    
    void pop(){
        if(tp != nullptr){
            auto temp = tp;
            tp = tp -> next;
            delete temp;
        }
    }
    
    bool empty(){
        return (tp == nullptr);
    }
    
    int main() {
        Stack<string> s;
        s.push("world");
        s.push("hello");
        while(!s.empty()){
            cout << s.top() << " " ;
            s.pop();
        }
        return 0;
    }
};
