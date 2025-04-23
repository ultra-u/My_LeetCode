#include <iostream>
#include <vector>
using namespace std;
//动态规划,dp[i][j]=dp[i-1][j]+dp[i][j-1]
class Solution {                                                                //每一步只能向下或者向右移动一步                         
public:
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m,vector<int>(n));                               //建立一个二维数组
         for(int i=0;i<m;++i){
            dp[i][0]=1;                                                          //当只有一行时，只有一种走法
         }
         for(int j=0;j<n;++j){
            dp[0][j]=1;                                                          //当只有一列时，只有一种走法
         }
         for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
         }
         return dp[m-1][n-1];
    }
};

int main(){
    int m{0},n{0};
    cout<<"please enter m:\n";
    cin>>m;
    cout<<"please enter n:\n";
    cin>>n;
    Solution s1;
    cout<<"the number of unique paths is "<<s1.uniquePaths(m,n);
}