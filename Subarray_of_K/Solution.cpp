#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {                                        //前缀和+哈希表优化
public:
    int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> map;
            map[0]=1;                                   //和为0的子数组总存在，需排除
            int count{0},pre{0};                        //count记录满足条件的子数组数量，pre记录前缀和
            for(int& num:nums){                         //num采用传引用，节省内存
                pre+=num;
                if(map.find(pre-k)!=map.end()){         //若键'pre-k'存在（即说明存在一个长度为k的子数组）
                    count +=map[pre-k];
                }
                map[pre]++;                             //存储当前前缀和并将其出现次数加1
            }
            return count;
    }
};

int main(){
    int k{0};
    vector<int> nums{};
    int size{0},num{0};
    cout<<"please enter K:\n";
    cin>>k;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"Sum is the subbarray of K: "<<s1.subarraySum(nums,k);
}