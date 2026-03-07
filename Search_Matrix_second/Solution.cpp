#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;  // 从右上角开始
        
        while(row < m && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] > target) {
                col--;  // 当前值太大，向左移动
            }
            else {
                row++;  // 当前值太小，向下移动
            }
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