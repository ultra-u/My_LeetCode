#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true;
            }
        }       
        return false;
    }
};

int main(){
    int size{0},val{0};
    cout<<"please enter size:\n";
    cin>>size;
    vector<int> nums;
    for(int i=0;i<size;i++){
        cout<<"please enter val:\n";
        cin>>val;
        nums.push_back(val);
    }
    Solution s;
    cout<<s.canJump(nums);
}