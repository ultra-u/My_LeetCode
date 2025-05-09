#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {                                                            //优先队列(堆)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;                                    //在优先队列中存储二元组 (num,index)，表示元素 num 在数组中的下标为 index
        for(int i=0;i<k;i++){                                               //先取前k个放入优先队列中
            q.emplace(nums[i],i);
        }
        vector<int> result={q.top().first};                                 //结果队列初始化先放入优先队列的第一个值
        for(int i=k;i<nums.size();++i){
            q.emplace(nums[i],i);                                           //滑动窗口并新值放入优先队列中
            while(q.top().second<=i-k){                                     //当队列顶部元素超出窗口范围
                q.pop();
            }
            result.push_back(q.top().first);
        }
        return result;
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
    int num{0},size{0},k{0};
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
    cout<<"the max sliding window is "<<s1.maxSlidingWindow(nums,k);
}