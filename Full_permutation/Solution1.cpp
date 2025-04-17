#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {                                                                    //使用STL中的next_permutation 算法
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());                                        //此步骤只是确保生成的排序是有序的，并非必须
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));                  
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