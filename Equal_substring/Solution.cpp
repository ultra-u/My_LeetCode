#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int result{0};
        vector<int> c{};                                           //用于辅助存储开销
        int cost{0};                                               //用于暂存开销
        int add_cost{0};                                           //用于开销的累加
        for(int i=0;i<s.size()&&i<t.size();i++){
            cost=abs(s[i]-t[i]);
            c.push_back(cost);
        }
        sort(c.begin(),c.end());
        if (!c.empty()) {
            add_cost = c[0];
            if (add_cost <= maxCost) {
                result = 1;
            } else {
                return 0;
            }

            for (int n = 1; n < c.size(); n++) {
                if (add_cost + c[n] <= maxCost) {
                    result++;
                    add_cost += c[n];
                } else {
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    string s{};
    string t{};
    int maxCost{0};
    cout<<"please enter s:\n";
    getline(cin,s);
    cout<<"please enter t:\n";
    getline(cin,t);
    cout<<"please enter maxCost:\n";
    cin>>maxCost;
    Solution s1;
    cout<<"max_length: "<<s1.equalSubstring(s,t,maxCost);
}