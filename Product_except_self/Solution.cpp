#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,1);                              //该数组用于存储每个位置左侧元素的乘积
        vector<int> right(n,1);                             //该数组用于存储每个位置右侧元素的乘积
        vector<int> result(n,1);
        for(int i=1;i<n;++i){                               //计算左侧乘积
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;--i){                            //计算右侧乘积
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;++i){
            result[i]=left[i]*right[i];
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
    int num{0},size{0};
    vector<int> nums;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"the product except self is "<<s1.productExceptSelf(nums);
}