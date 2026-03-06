#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
public:
    string minWindow(string s,string t){
        vector<int> count(128,0);
        for(char c:t)  count[c]++;
        int left{0},right{0},minLeft{0},minLen=INT_MAX,match{0};
        while(right<s.size()){
            if(count[s[right]]-->0)   match++;
            while(match==t.size()){
                if(right-left+1<minLen){
                    minLeft=left;
                    minLen=right-left+1;
                }
                if(count[s[left]]++==0)   match--;
                left++;
            }
            right++;
        }
        return minLen==INT_MAX?"":s.substr(minLeft,minLen);
    }
    friend ostream& operator<<(ostream& out,const string& result);
};

ostream& operator<<(ostream& out,const string& result){
    out << "\"" << result << "\"";
    return out;
}

int main(){
    string s{},t{};
    cout<<"please enter s:\n";
    getline(cin,s);
    cout<<"please enter t:\n";
    getline(cin,t);
    Solution s1;
    cout<<"the minimum window is "<<s1.minWindow(s,t);
}