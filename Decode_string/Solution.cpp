#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
          string result;
          stack<pair<int,int>> stk;                                 //用于存储数字和对应的字符串位置
          int count{0};                                             //记录倍率
          for(auto& x:s){
                if(isdigit(x)){                                     //若当前字符为数字
                    count=10*count+(x-'0');                         //处理多位数
                }
                else if(x=='['){                                    //遇到左括号时,则将当前数字和字符串的当前长度压入栈，并重置 count 为 0
                    stk.push({count,result.size()});
                    count=0;
                }
                else if(isalpha(x)){                                //若当前字符为字母时
                    result+=x;
                }
                else if(x==']'){                                    //遇到右括号时,则从栈中弹出数字 n 和字符串的起始位置
                    int n=stk.top().first;
                    string str = result.substr(stk.top().second, result.size() - stk.top().second);
                    for(int i=0;i<n-1;i++){
                        result+=str;
                    }
                    stk.pop();
                }
          }
          return result;
    }
};

int main(){
    string s;
    cout<<"please enter string:\n";
    getline(cin,s);
    Solution s1;
    cout<<"decode: "<<s1.decodeString(s);
}