#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

class Solution {                                            //采用栈来进行括号的匹配
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){                     //处理左括号：若遇左括号，则进行压栈处理
                stk.push(c);
            }
            else{
                if(stk.empty()){                            //当遇右括号时，出栈栈顶元素进行匹配，当若栈空一定匹配失败
                    return false;
                }
                if(c-stk.top()==1||c-stk.top()==2){         //对应括号的Ascll码相差1或2，可以利用这个特性进行匹配判断
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();                                 //最后若全都匹配成功，则栈为空，反之失败
    }
};

int main(){
    string s{};
    cout<<"please enter s:\n";
    getline(cin,s);
    Solution s1;
    cout<<s<<"is valid: "<<s1.isValid(s);
}