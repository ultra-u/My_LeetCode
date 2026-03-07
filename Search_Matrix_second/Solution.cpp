#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / n][mid % n];
            if(mid_value == target) return true;
            else if(mid_value < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix;
    int line, column, target;
    cout<<"Enter the number of lines:";
    cin>>line;
    cout<<"Enter the number of columns:";
    cin>>column;
    cout<<"Enter the target number:";
    cin>>target;
    for(int i = 0; i < line; i++){
        vector<int> row(column);
        for(int j = 0; j < column; j++){
            cout<<"Enter number for matrix["<<i<<"]["<<j<<"]:";
            cin>>row[j];
        }
        matrix.push_back(row);
    }
    Solution s;
    bool result = s.searchMatrix(matrix, target);
    cout<<"Does the target exist in the matrix? "<<(result ? "true" : "false")<<endl;
}