#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxValue(int n, int index, int maxSum) {
           // 将maxSum想象成面积，数组每个元素是宽为1，高度为对应元素值的矩形 
        // 给index位置逐步增加高度
        // 每次增加高度时计算 新影响的周边元素数量
        int remainValue = maxSum - n;   // 每个元素初始值为1

        int heap = 1; // index位置的高度
        int t = 0; // 单次对index增加1高度会影响到的元素数量

        for (int i = 0; t < n; i++) {
            t = min(i, index) + min(i, n - (index + 1)) + 1; // 对左边的影响 min(i, index) + 对右边的影响 + 对index的影响
            if (remainValue < t) {
                break;
            }

            remainValue -= t;
            heap++;
        }

        if (remainValue > n) {
            heap += remainValue / n;
        }

        return heap;
    }
};

int main(){
    int n{0},index{0},maxSum{0};
    cout<<"please enter size:\n";
    cin>>n;
    cout<<"please enter index:\n";
    cin>>index;
    cout<<"please enter maxSum:\n";
    cin>>maxSum;
    Solution s1;
    cout<<"The value of arrays that meet the requirements: "<<s1.maxValue(n,index,maxSum);
}