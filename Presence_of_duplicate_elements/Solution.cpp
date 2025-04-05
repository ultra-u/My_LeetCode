#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {                                    //使用哈希表来存储每个元素最后一次出现的位置
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> lastSeen;
            for (int i = 0; i < nums.size(); ++i) {
                if (lastSeen.count(nums[i]) && abs(i - lastSeen[nums[i]]) <= k) {
                    return true;
                }
                lastSeen[nums[i]] = i;
            }
            return false;
    }
};

int main(){
    vector<int> nums{};
    int num{0};
    int k{0};
    int size{0};
    cout<<"please enter k:\n";
    cin>>k;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"Contains near by duplicate: "<<std::boolalpha<<s1.containsNearbyDuplicate(nums,k);
}