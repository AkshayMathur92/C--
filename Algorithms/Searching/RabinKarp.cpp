#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

inline bool string_compare(string s1, string s2){
    return s1==s2;
}

vector<int> RabinKarpSearch(const string &text, const string &pattern){
    if(text.size() < pattern.size())
        return vector<int>();
    const auto d = 101;
    const auto high_order = pow(d, pattern.size() - 1);
    auto t_itr = text.begin();
    auto p_itr = pattern.begin();
    vector<int> matches;
    
    unsigned long long int ps= 0;
    decltype(ps) ts = 0;
    
    while(p_itr != pattern.end()){
        ps = ps * d + *p_itr;
        ts = ts * d + *t_itr;
        p_itr++;
        t_itr++;
    }
    
    if(ts == ps && string_compare(pattern, string(text.begin(), text.begin() + pattern.size()))) {
        matches.push_back(0);
    }
    
    t_itr = text.begin();
    
    while(t_itr != text.begin() + (text.size () - pattern.size())){
        
        ts = (d * (ts - *t_itr * high_order)) + *(t_itr + pattern.size());
        
        if(ts == ps && string_compare(pattern, string(t_itr + 1, t_itr + 1 + pattern.size()))) {
            matches.push_back(t_itr - text.begin() + 1);
        }
        
        t_itr++;
    }
    return matches;
}

int main(){
    string t = "abcdabcdsdfjljsgnol efljasfjksabcdf123klj34njlas lksabcdf89m.ssgnold";
    string p = "ab";
    
    for(auto &i : RabinKarpSearch(t, p))
        cout << "Match found at " << i << endl;
}
