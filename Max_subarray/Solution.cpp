#include <iostream>
#include <vector>
using namespace std;

class Solution {                                //动态规划
public:
    int maxSubArray(vector<int>& nums) {
        int pre{0};
        int maxarray=nums[0];
        for(const int &num:nums){
            pre=max(pre+num,num);
            maxarray=max(maxarray,pre);
        }
        return maxarray;
    }
};

int main(){
    int size{0};
    int num{0};
    vector<int> nums{};
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"the max of subarray is "<<s1.maxSubArray(nums);
}