#include <iostream>
#include <string.h>
#include <unordered_set>
using namespace std;

class Solution {                                                  //滑动窗口
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sets;                                 //采用哈希集合来判断是否有重复字符
        int i{0};                                                 //设置滑动窗口的左边界
        int longs{0};
        for(int j=0;j<s.size();j++){                              //j用于滑动窗口的右边界，并移动
            while(i<j&&sets.count(s[j])!=0){                      //若存在重复字符，移除左边界字符并右移左边界
                sets.erase(s[i++]);
            }
            sets.insert(s[j]);
            longs=max(longs,j-i+1);
        }
        return longs;
    }
};

int main(){
    string s{};
    cout<<"please enter s:\n";
    getline(cin,s);
    Solution s1;
    cout<<"Longest string without report: "<<s1.lengthOfLongestSubstring(s);
}