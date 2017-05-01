#include <iostream>
#include <vector>

template <typename T>
class MinHeap{
    std::vector<T> v;
    void percolateup(int key){
        if(v.size() < 2 || key >= v.size())
            return;
        auto parent = (key%2 == 0)? (key >> 1) - 1 : key >> 1;
        while(parent >= 0){
            if(v[parent] > v[key]){
                std::swap(v[parent], v[key]);
            }
            key = parent;
            parent = (key%2 == 0)? (key >> 1) - 1 : key >> 1;
        }
    }
    void percolatedown(int key){
        if(v.size() < 2  || key >= v.size())
            return;
        auto lchild = (key << 1) + 1;
        auto rchild = (key << 1) + 2;
        if((lchild < v.size() && v[key] > v[lchild])){
            std::swap(v[key], v[lchild]);
            percolatedown(lchild);
        }
        else if((rchild < v.size() && v[key] > v[rchild])){
            std::swap(v[key], v[lchild]);
            percolatedown(rchild);
        }
    }
public:
    MinHeap(){}
    
    void insertKey(T key){
        v.push_back(key);
        percolateup(v.size() - 1);
        
    }
    void deleteKey(){
        
    }
    T getMin(){
        return v.front();
        
    }
    void extractMin(){
        std::swap(v[0], v[v.size() - 1]);
        v.pop_back();
        percolatedown(0);
    }
};

int main(){
    MinHeap<int> mh;
    mh.insertKey(8);
    std::cout << mh.getMin() << std::endl;
    mh.insertKey(7);
    std::cout << mh.getMin() << std::endl;
    mh.insertKey(9);
    std::cout << mh.getMin() << std::endl;
    mh.insertKey(3);
    std::cout << mh.getMin() << std::endl;
    mh.insertKey(16);
    std::cout << mh.getMin() << std::endl;
    mh.insertKey(10);
    std::cout << mh.getMin() << std::endl;
    mh.extractMin();
    std::cout << mh.getMin() << std::endl;
    mh.insertKey(14);
    std::cout << mh.getMin() << std::endl;
    
}