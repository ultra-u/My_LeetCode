#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> countmap;                                     //建立一个哈希表来统计每个数字出现的次数
            for(int num:nums){
                countmap[num]++;
            }
            auto compare = [](const std::pair<int,int>& a,const std::pair<int,int>& b) {	        //比较函数，用于将优先列配置成最大堆
                return a.second>b.second;
            };
            priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)>heap(compare);        //建立一个优先队列，是一个基于比较函数的最小堆
            for(auto& p:countmap){                                                    //将哈希表中的元素填充到堆中
                heap.push(p);
                if(heap.size()>k){
                    heap.pop();
                }
            }
            vector<int> topK;                                                       //辅助数组，用于存储结果元素
            while(!heap.empty()){
                topK.push_back(heap.top().first);
                heap.pop();
            }
            reverse(topK.begin(), topK.end());
            return topK;
    }
    friend ostream& operator<<(ostream& out,const vector<int>& result);
};

ostream& operator<<(ostream& out,const vector<int>& result){
    out << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        out << result[i];
        if (i != result.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main(){
    int size{0},num{0},k{0};
    vector<int> nums{};
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
    cout<<"the top "<<k<<" frequent is"<<s1.topKFrequent(nums,k);
}