#include <vector>
#include <iostream>
#include <numeric>

template <typename T>
T  merge_arrays(T &v1){
	return v1;
}
template <typename T>
T  merge_arrays(T &v1 , T &v2){
    T  res;
    auto iv1 = v1.begin();
    auto iv2 = v2.begin();
    while(iv1 != v1.end() && iv2 != v2.end()){
        if(*iv1 < *iv2){
            res.push_back(*iv1);
            iv1++;
        }
        else{
            res.push_back(*iv2);
            iv2++;
        }
    }
    if(iv1 != v1.end())
        std::copy(iv1, v1.end(),back_inserter(res));
    else
        std::copy(iv2, v2.end(),back_inserter(res));
    return res;
}
template <typename T, typename... Tail>
T merge_arrays(T &v1 , T &v2,Tail... tail){
	auto res1 = merge_arrays(v1,v2);
	auto res2 = merge_arrays(tail...);
	return merge_arrays(res1, res2);
}
int main(){
    std::vector<int> v1 = {1,4,6};
    std::vector<int> v2 = {2,7,9};
    std::vector<int> v3 = {3,5,8};
    std::vector<int> v4 = {10};
    std::vector<int> v5 = {11};
    for(auto i : merge_arrays(v1,v2,v3,v4,v5)){
    	std::cout << i << " ";
    }
}