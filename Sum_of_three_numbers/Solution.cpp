#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());                              //先对原有数组进行排序
        int left{0};
        int right=nums.size()-1;
        vector<vector<int>> result;                                 //创建一个空容器来存储结果
        for(int i=0;i<nums.size()-2;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;                   //跳过重复元素，其中i>0用于排除元素数量小于3的情况
            left=i+1;
            right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    result.push_back({nums[i],nums[left],nums[right]});     //存储目标三元组
                    while(left<right&&nums[left]==nums[left+1]) ++left;     //跳过重复元素
                    while(left<right&&nums[right]==nums[right+1]) --right;  //跳过重复元素
                    ++left;
                    --right;
                }
                else if(sum<0)  ++left;
                else    --right;
            }
        }
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
    vector<int> nums={};
    int x{0};                                                       //存储用户想要输入数组的大小
    int num{0};                                                     //暂存用户输入的数组元素
    cout<<"How many elements do I need to create in an array?\n";
    cin>>x;
    for(int i=0;i<x;i++){
        cout<<"Enter the array elements one by one:\n";
        cin>>num;
        nums.push_back(num);                                        //添加到容器vector中
    }
    for(int n:nums){                                                //打印测试一下当前数组元素
        cout<<n<<" ";
    }
    cout<<"\n";
    Solution s1;
    cout<<s1.threeSum(nums);
}