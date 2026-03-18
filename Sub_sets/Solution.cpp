#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(nums, 0, path, res);
        return res;
    }

    void backtracking(vector<int>& nums, int startIndex, vector<int>& path, vector<vector<int>>& res){
        res.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1, path, res);
            path.pop_back();
        }
    }
};

int main(){
    int size{0},val{0};
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> nums;
    cout << "Enter the elements of the array: \n";
    for(int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> val;
        nums.push_back(val);
    }
    Solution s;
    vector<vector<int>> result = s.subsets(nums);
    cout << "Subsets are: " << endl;
    for(const auto& subset : result){
        cout << "[";
        for(int j = 0; j < subset.size(); j++){
            cout << subset[j];
            if(j < subset.size() - 1){
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}
