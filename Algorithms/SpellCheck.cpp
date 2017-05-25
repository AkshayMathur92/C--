#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <cctype>
#include <functional>

std::map<std::string, unsigned long int> WORDS;

std::string toLower(std::string data){
    std::transform(data.begin(), data.end(), data.begin(), [](char in){
        if(in<='Z' && in>='A')
            return char(in-('Z'-'z'));
        return char(in);
    });
    return data;
}

int edit_distance(std::string s1, std::string s2){
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

std::string distance(std::string &s, int x){
    std::vector<std::pair<std::string, unsigned long int> > suggestions;
    copy_if(WORDS.begin(), WORDS.end(), back_inserter(suggestions), [&](const std::pair<std::string, unsigned long int> &p){
        return edit_distance(p.first, s) == x;
    });
    auto same_length  = find_if(suggestions.begin(), suggestions.end(), [&](const std::pair<std::string, unsigned long int>&p){
        return (p.first.length() == s.length());});
    if(same_length != suggestions.end()){
        suggestions.erase(remove_if(suggestions.begin(), suggestions.end(), [&](const std::pair<std::string, unsigned long int>&p){
            return (p.first.length() != s.length());
        }),suggestions.end());
    }
    auto start_with  = find_if(suggestions.begin(), suggestions.end(), [&](const std::pair<std::string, unsigned long int>&p){
        return (p.first[0] == s[0]);});
    if(start_with != suggestions.end()){
        suggestions.erase(remove_if(suggestions.begin(), suggestions.end(), [&](const std::pair<std::string, unsigned long int>&p){
            return (p.first[0] != s[0] );
        }),suggestions.end());
    }
    auto ans = max_element(suggestions.begin(), suggestions.end(), [&](const std::pair<std::string, unsigned long int>&p1, const std::pair<std::string, unsigned long int>&p2){
        return p1.second < p2.second;
    });
    if(ans != suggestions.end())
        return ans -> first;
    else
        return "";
}

std::string spellCheck(std::string s){
    s = toLower(s);
    std::string ans;
    if(WORDS.find(s) != WORDS.end()){
        return s;
    }
    if((ans = distance(s, 1)) != "" || (ans = distance(s, 2)) != ""){
        return ans;
    }
    return "";
}

void init_Words(){
    std::ifstream ifs("Big.txt");
    std::regex pat (R"((\w)+)");
    for (std::string line; getline(ifs,line); ) {
        // std::cout << line << '\n';// read into line buffer
        std::smatch matches; //matched strings go here
        if (regex_search(line ,matches,pat)) {
            for(auto &match : matches){
                auto match_str = toLower(std::string(match));
                if(WORDS.find(match_str) == WORDS.end())
                    WORDS[match_str] = 1;
                else
                    WORDS[match_str] = WORDS[match_str] + 1;
            }
        }
    }
}
int main(){
    init_Words();
    // for(auto itr = WORDS.begin(); itr != WORDS.end(); itr++){
    //  std::cout << (itr -> first) << " " << itr -> second << std::endl;
    // }
    std::cout << spellCheck("wrok")<< std::endl;
    std::cout << spellCheck("ues")<< std::endl;
    std::cout << spellCheck("somthing")<< std::endl;
    std::cout << spellCheck("thenk")<< std::endl;
    std::cout << spellCheck("measure")<< std::endl;
    std::cout << spellCheck("hre")<< std::endl;
    std::cout << spellCheck("sopa")<< std::endl;

}