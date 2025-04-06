#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        unordered_set<int> num_set;                                 //构建一个哈希表，在插入时可以直接去重，并且查询操作时间复杂度O(1)
        for (const int& num : nums) {
            num_set.insert(num);
        }
        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {                         //查询当前数组元素有无存在开头(前一个数)，如当前为100，则查询99
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {            //记录连续序列的个数来匹配最长序列
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;   
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
    cout<<"Longest continuous array: "<<s1.longestConsecutive(nums);
}