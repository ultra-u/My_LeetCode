#include <iostream>
#include <vector>
using namespace std;

class Solution {                                            //采用二分查找来确定查询位置
public:
    int searchInsert(vector<int>& nums, int target) {
            int left=0,right=nums.size()-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(nums[mid]<target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            return left;
    }
};

int main(){
    int num{0},size{0};
    int target{0};
    vector<int> nums{};
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    cout<<"please enter target:\n";
    cin>>target;
    Solution s1;
    cout<<"Search for the insertion position is "<<s1.searchInsert(nums,target);
}