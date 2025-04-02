#include <iostream>
#include <vector>
using namespace std;

class Solution {                                                            //贪心，降低暴力解的时间复杂度
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long result{0};
            for(int k=2;k<nums.size();k++){
                int i=nums[0];                                              //i用于维护[0,j)范围的最大值
                for(int j=1;j<k;j++){
                    result=max(result,(long long)(i-nums[j])*nums[k]);
                    i=max(i,nums[j]);
                }
            }
            return result;
    }
};

int main(){
    vector<int> nums{};
    int size{0};
    int num{0};
    cout<<"please enter the size of vector:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter nums:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"maximum: "<<s1.maximumTripletValue(nums);
}