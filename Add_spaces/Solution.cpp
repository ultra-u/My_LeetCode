#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution {                                                        //双指针，分别遍历s和space
    public:
        string addSpaces(string s, vector<int>& spaces) {
            string result{};
            int ptr{0};
            for(size_t i=0;i<s.size();i++){
                if(ptr<spaces.size()&&spaces[ptr]==i){
                    result.push_back(' ');
                    ++ptr;
                }
                result.push_back(s[i]);
            }
            return result;
    }
};

int main(){
    string s{};
    vector<int> spaces{};
    int size{0};
    int sp{0};
    cout<<"please enter s:\n";
    getline(cin,s);
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter spaces:\n";
        cin>>sp;
        spaces.push_back(sp);
    }
    Solution s1;
    cout<<"After modification: "<<s1.addSpaces(s,spaces);
}