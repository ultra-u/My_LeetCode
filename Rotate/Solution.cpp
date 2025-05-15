#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        cout<<"[";
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<",";
        }
        cout<<"]";
    }
};

int main(){
    int num{0},k{0},size{0};
    vector<int> nums{};
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    cout<<"please enter k:\n";
    cin>>k;
    Solution s1;
    s1.rotate(nums,k);
}