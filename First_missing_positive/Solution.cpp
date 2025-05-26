#include <iostream>
#include <vector>
using namespace std;

class Solution {                                                    //哈希改造+索引标记
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i){                                         //将非正数替换为一个大于数组长度的数
            if(nums[i]<=0||nums[i]>n){
                nums[i]=n+1;
            }
        }
        for(int i=0;i<n;++i){                                       //将数组中的正整数映射到对应的索引上
            int num=abs(nums[i]);
            if(num<=n){
                nums[num-1]=-abs(nums[num-1]);
            }
        }
        for(int i=0;i<n;++i){                                       //寻找第一个未被标记为负数的索引
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};

int main(){
    int num{0},size{0};
    vector<int> nums;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"the smallest positive integer that does not appear is "<<s1.firstMissingPositive(nums);
}