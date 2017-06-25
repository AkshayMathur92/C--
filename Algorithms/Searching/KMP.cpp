#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline bool string_compare(string s1, string s2){
    return s1==s2;
}

vector<int> ComputePrefixFuntion(const string &P){
    
    vector<int> prefix(P.size());
    prefix[0] = 0;
    int k = 0;
    for(auto q = 1; q < P.size(); q++){
        while(k > 0 && P[k] != P[q]){
            k = prefix[k - 1];
        }
        if(P[k] == P[q])
            k++;
        prefix[q] = k + 1;
    }
    return move(prefix);
}

vector<int> KMP(const string& text, const string& pattern){
    
    const auto prefix = ComputePrefixFuntion(pattern);
    auto k = 0;
    vector<int> matches;
    auto q = 0;
    for(auto t = text.begin(); t != text.end(); t++){
        while(q > 0 && pattern[q] != *t)
            q = prefix[q - 1];
        if(pattern[q] == *t)
            q++;
        if(q == pattern.size()){
            matches.push_back(t - text.begin() - pattern.size() + 1);
            q = prefix[q - 1];
        }
    }
    return matches;
}

int main(){
    string t = "abababacacdabcdsdfjljsgnol efljasfjksabcdf123klj34njlas lksabcdf89m.ssgnold";
    string p = "ab";
    
    for(auto &i : KMP(t, p))
        cout << "Match found at " << i << endl;
}