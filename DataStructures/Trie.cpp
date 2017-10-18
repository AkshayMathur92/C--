//
//  Trie.cpp
//  LinkList
//
//  Created by Akshay Mathur on 17/10/17.
//  Copyright © 2017 Akshay Mathur. All rights reserved.
//

#include <iostream>
#include <array>
#include <string>
using namespace std;

class Trie{
    struct TrieNode{
        struct ch{
            array<TrieNode*, 26> children{};
            TrieNode* operator[](int i)const {
                auto temp = (tolower(i) - 'a') % 26;
                return children[temp];
            }
            TrieNode*& operator[](int i){
                auto temp = (tolower(i) - 'a') % 26;
                return children[temp];
            }
            ~ch(){
                for(int i = 0; i < 26; i++){
                    if(children[i] != nullptr)
                        delete children[i];
                }
            }
        };
        ch children;
        bool isEnd;
        TrieNode():isEnd(false){}
    };
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    ~Trie(){
        delete root;
    }
    
    void add(string s){
        TrieNode *itr = root;
        for(int i = 0; i < s.length(); i++){
            if(!itr -> children[s[i]]){
                itr -> children[s[i]] = new TrieNode();
            }
            itr = itr -> children[s[i]];
        }
        itr -> isEnd = true;
    }
    
    bool search(string s){
        TrieNode *itr = root;
        for(int i = 0; i < s.length(); i++){
            if(!itr -> children[s[i]])
                return false;
            itr = itr -> children[s[i]];
            if(i == s.length() - 1 && itr -> isEnd )
                return true;
        }
        return false;
    }
};

int main(){
    {
        Trie t;
        t.add("Hello");
        t.add("World");
        cout << t.search("Hello") << endl;
        cout << t.search("dog") << endl;
    }
}
