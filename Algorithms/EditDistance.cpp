#include <iostream>
#include <string>
#include <vector>

int edit_distance(const std::string &s1, const std::string &s2, const int m , const int n){
    if(s1.length() == m)
        return s2.length() - n;
    if(s2.length() == n)
        return s1.length() - m;
    if(s1[m] == s2[n])
        return edit_distance(s1,s2,m+1,n+1);
    else
        return 1 + std::min(edit_distance(s1,s2,m+1, n+1), std::min(edit_distance(s1,s2,m+1, n), edit_distance(s1, s2, m, n+1)));
}

int edit_distance(std::string s1, std::string s2){
    return edit_distance(s1,s2, 0 , 0);
}

int edit_distance_2(std::string s1, std::string s2){
    std::vector <std::vector<int> > v(s1.length() + 1, std::vector<int>(s2.length() + 1));
    for(int i = 0 ; i <= s1.length(); i ++){
        for(int j = 0; j <= s2.length(); j++){
            if(i == 0)
                v[i][j] = j;
            else if(j == 0)
                v[i][j] = i;
            else if(s1[i - 1] == s2[j - 1])
                v[i][j] = v[i-1][j-1];
            else
                v[i][j] = std::min(v[i-1][j-1],std::min(v[i-1][j], v[i][j-1])) + 1;
        }
    }
    return v[s1.length()][s2.length()];
}

int main(){
    std::cout << edit_distance("hell", "hell")<< std::endl;
    std::cout << edit_distance("hello", "hellf")<< std::endl;
    std::cout << edit_distance("chair", "hair")<< std::endl;
    std::cout << edit_distance("chair", "chir")<< std::endl;
    std::cout << edit_distance("soon", "moon")<< std::endl;
    std::cout << edit_distance("song", "tong")<< std::endl;
    std::cout << edit_distance("god", "good")<< std::endl;
    std::cout << edit_distance("", "this")<< std::endl;
    std::cout << edit_distance("negative", "positive")<< std::endl;
    std::cout << edit_distance_2("hell", "hell")<< std::endl;
    std::cout << edit_distance_2("hello", "hellf")<< std::endl;
    std::cout << edit_distance_2("chair", "hair")<< std::endl;
    std::cout << edit_distance_2("chair", "chir")<< std::endl;
    std::cout << edit_distance_2("soon", "moon")<< std::endl;
    std::cout << edit_distance_2("song", "tong")<< std::endl;
    std::cout << edit_distance_2("god", "good")<< std::endl;
    std::cout << edit_distance_2("", "this")<< std::endl;
    std::cout << edit_distance_2("negative", "positive")<< std::endl;
}
