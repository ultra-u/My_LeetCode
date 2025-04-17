#include <iostream>
#include <vector>
using namespace std;

class Solution {                                                                    //采用回溯法解决
public:
vector<int> path;                                                       //用于存储当前排列
vector<vector<int>> result;                                             //用于存储所有可能的排列
void backTrack(const vector<int>& nums, vector<bool>& visited) {
    if(path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); ++i) {
        if(!visited[i]) {
            path.push_back(nums[i]);
            visited[i] = true;                                          //标记为已访问
            backTrack(nums, visited);                                   //递归中找到下一个排序
            path.pop_back();                                            //移除最后一个元素
            visited[i] = false;                                         //标记为未访问
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<bool> visited(n, false);
    path.clear(); 
    result.clear();
    backTrack(nums, visited);
    return result;
}
    friend ostream& operator<<(ostream& out,const vector<vector<int>>& result);     //将重载运算符函数设置为友元函数，便于其重定义
};

ostream& operator<<(ostream& out,const vector<vector<int>>& result){    //重载运算符"<<"
    out << "[";
    for (size_t i = 0; i < result.size(); ++i) {                        //注意result此时为二维向量
        out << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            out << result[i][j];
            if (j < result[i].size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        if (i < result.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main(){
    vector<int> nums{};
    int num{0};
    int size{0};
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"full permutation is"<<s1.permute(nums);
}