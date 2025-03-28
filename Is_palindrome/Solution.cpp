#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&&x!=0))   return false;
        string str=to_string(x);                        //将整数转为字符串
        int left=0;                                     //“双指针”法
        int right=str.length()-1;
        while(left<right){
            if(str[left]!=str[right])   return false;
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    int x{0};
    cout<<"请输入一个整数：\n";
    cin>>x;
    Solution s1;
    if(s1.isPalindrome(x))  cout<<"true";
    else    cout<<"false";
}
