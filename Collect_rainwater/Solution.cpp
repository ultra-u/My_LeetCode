#include <iostream>
#include <vector>
using namespace std;

class Solution {                                                //双指针
public:
    int trap(vector<int>& height) {
        int result{0};
        int left=0,right=height.size()-1;
        int leftMax{0},rightMax{0};                             //用于记录左右侧墙高度
        while(left<right){
            leftMax=max(leftMax,height[left]);
            rightMax=max(rightMax,height[right]);
            if(height[left]<height[right]){
                result+=leftMax-height[left];
                ++left;
            }
            else{
                result+=rightMax-height[right];
                --right;
            }
        }
        return result;
    }
};

int main(){
    int size{0},h{0};
    vector<int> height;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter h:\n";
        cin>>h;
        height.push_back(h);
    }
    Solution s1;
    cout<<"The amount of rainwater that can be received is "<<s1.trap(height);
}