#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> findAnagrams(string s,string p){
        vector<int> result;
        if(s.size()<p.size())  return result;
        vector<int> count(26,0);
        for(char c:p)  count[c-'a']++;
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']--;
            if(i>=p.size())   count[s[i-p.size()]-'a']++;
            if(all_of(count.begin(),count.end(),[](int x){return x==0;}))   result.push_back(i-p.size()+1);
        }
        return result;
    }
    friend ostream& operator<<(ostream& out,const vector<int>& result);
};

ostream& operator<<(ostream& out,const vector<int>& result){
    out << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        out << result[i];
        if (i < result.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main(){
    string s{},p{};
    cout<<"please enter s:\n";
    getline(cin,s);
    cout<<"please enter p:\n";
    getline(cin,p);
    Solution s1;
    cout<<"find all anagrams: "<<s1.findAnagrams(s,p);
}