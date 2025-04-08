#include <iostream>
#include <vector>
using namespace std;
//最容易想到的解法就是两次for循环，把所有情况都考虑到，但时间复杂度就高了。
//这里采用双指针，左右指针每次尽可能移动较短的那块板
class Solution {                                    
public:
    int maxArea(vector<int>& height) {
            int final{0},curry{0};
            int left=0,right=height.size()-1;
            while(left<right){
                curry=min(height[left],height[right])*(right-left);
                final=max(final,curry);
                if(height[left]<=height[right]){
                    ++left;
                }
                else    --right;  
            }
            return final;
    }
};

int main(){
    int size{0};
    int height{0};
    vector<int> heights{};
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter height:\n";
        cin>>height;
        heights.push_back(height);
    }
    Solution s1;
    cout<<"The most water area is "<<s1.maxArea(heights);
}