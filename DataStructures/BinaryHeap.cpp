#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class MinHeap{
    std::vector<T> v;
public:
    MinHeap(){}
    
    void insertKey(T key){
        v.push_back(key);
        percolateup(v, v.size() - 1);
    }
    void deleteKey(T key){
    	auto itr = std::find(v.begin(), v.end(), key);
    	if(itr == v.end())
    		return;
    	auto pos = itr - v.begin();
    	std::swap(v[pos], v[v.size() - 1]);
    	v.pop_back();
    	percolatedown(v,pos);
    }
    T getMin(){
        return v.front();
        
    }
    void extractMin(){
        std::swap(v[0], v[v.size() - 1]);
        v.pop_back();
        percolatedown(v,0);
    }
    template <typename N>
    static void percolateup(std::vector<N> &v, int key){
        if(key >= v.size())
            return;
        auto parent = (key % 2 == 0)? (key >> 1) - 1 : key >> 1;
        if(parent >= 0 && v[parent] > v[key]){
            std::swap(v[parent], v[key]);
            percolateup(v, parent);
        }
    }
    template <typename N> 
    static void percolatedown(std::vector<N> &v, int key){
        if(key >= v.size())
            return;
        auto lchild = (key << 1) + 1;
        auto rchild = (key << 1) + 2;
        if((lchild < v.size() && v[key] > v[lchild])){
            std::swap(v[key], v[lchild]);
            percolatedown(v,lchild);
        }
        else if((rchild < v.size() && v[key] > v[rchild])){
            std::swap(v[key], v[lchild]);
            percolatedown(v,rchild);
        }
    }
    template<typename N>
    static void buildminheap(std::vector<N> &v){
        for(int i =v.size()/2; i <v.size() ; i++){
            percolateup(v,i);
        }
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
    mh.deleteKey(7);
    std::cout << mh.getMin() << std::endl;
    auto vec = std::vector<int>()={16,14,10,8,7,9,3,2,4,1};
    MinHeap<int>::buildminheap(vec);
    for(auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    
}