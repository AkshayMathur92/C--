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
#include <vector>
using namespace std;

class Trie{
    struct TrieNode{
        struct ch{
            TrieNode* children[26];
            TrieNode* operator[](int i)const {
                auto temp = (tolower(i) - 'a') % 26;
                return children[temp];
            }
            TrieNode*& operator[](int i){
                auto temp = (tolower(i) - 'a') % 26;
                return children[temp];
            }
            ch(){
                for(int i = 0; i < 26; i++){
                        children[i] = nullptr;
                }
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
    
    bool isLeaf(TrieNode* itr){
        for(int i = 'a'; i <= 'z'; i ++){
            if(itr ->children[i]){
                return false;
            }
        }
        return true;
    }
    
    bool remove(TrieNode * itr, string s, int index){
        if(itr == nullptr)
            return false;
        if(index == s.length() - 1){
            if(isLeaf(itr)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(remove(itr -> children[s[index + 1]], s, index + 1)){
                delete itr -> children[s[index + 1]];
                itr -> children[s[index + 1]] = nullptr;
                if(isLeaf(itr)){
                    itr  -> isEnd =true;
                    return true;
                }
                else
                    return false;
            }
            return false;
        }
    }
    
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
    
    bool search(string s) const{
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
    
    void remove(string s)
    {
        if( s.size() > 0 )
        {
            remove(root -> children[s[0]], s, 0);
        }
    }
    
};

int main(){
    {
        Trie t;
        t.add("Hello");
        t.add("World");
        cout << t.search("Hello") << endl;
        cout << t.search("dog") << endl;
        t.remove("Hello");
        cout << t.search("Hello") << endl;
        t.add("she");
        t.add("sells");
        t.add("sea");
        t.add("shore");
        cout << t.search("she") << endl;
        cout << t.search("sells") << endl;
        cout << t.search("sea") << endl;
        cout << t.search("shore") << endl;
        
        t.remove("sea");
        cout << t.search("she") << endl;
        cout << t.search("sells") << endl;
        cout << t.search("sea") << endl;
        cout << t.search("shore") << endl;
    }
}
