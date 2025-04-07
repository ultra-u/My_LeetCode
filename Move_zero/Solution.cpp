#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left{0};                        //左指针左侧为处理好的非零数
        int right{0};                       //右指针用于遍历寻找非零数
        while(right<nums.size()){
            if(nums[right]){                //若右指针寻找到非零数，则左右指针交换内容，确保左指针左侧为非零数
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
        cout<<"[";
        for(int num:nums){
            cout<<num<<",";
        }
        cout<<"]";
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
    s1.moveZeroes(nums);
}