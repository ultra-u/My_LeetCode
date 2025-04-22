#include <iostream>
using namespace std;

class Solution {                                            //f(x)=f(x-1)+f(x-2),且f(0)=1,f(1)=1,f(2)=2
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int dp[n+2];                              //n+2是保证n=3时可以正常进入循环
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return  dp[n];                                           
    }
};

int main(){                             
    int n{0};
    cout<<"please enter n:\n";
    cin>>n;
    Solution s1;
    cout<<"the number of solution is "<<s1.climbStairs(n);
}