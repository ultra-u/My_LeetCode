#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Solution {
public:
    int inversion(int x) {
        string str=to_string(x);
        reverse(str.begin(),str.end());         //翻转字符
        int result{0};
        try{
            result=stoi(str);                   //变回数字
            if(x<0) result=-result;	            //若x为负数，则结果添加“-”    
        }catch(exception& ex){                  //若溢出，返回零
            result=0;
        }     
        return result;             
    }
};

int main(){
    int x;
    cout<<"请输入一个整数：\n";
    cin>>x;
    Solution s1;
    cout<<s1.inversion(x);
}