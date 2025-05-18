#include <iostream>
#include <vector>
using namespace std;

class Solution {                                                    //将二维矩阵形成一个升序数组，然后用二分查找解决
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int line=matrix.size(),column=matrix[0].size();
        int low=0,high=line*column-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            int x=matrix[mid/column][mid%column];                   //取mid对应的矩阵的值
            if(x<target){
                low=mid+1;
            }
            else if(x>target){
                high=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix;
    int line{0},column{0},num{0},target{0};
    cout<<"please enter line:\n";
    cin>>line;
    cout<<"please enter column:\n";
    cin>>column;
    matrix.resize(line, vector<int>(column));                       //输入行数和列数后调整二维数组的大小，不然后续数组无法赋值
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            cout<<"please enter num:\n";
            cin>>num;
            matrix[i][j]=num;
        }
    }
    cout<<"please enter target:\n";
    cin>>target;
    Solution s1;
    cout<<target<<" Does it exist in this matrix: "<<s1.searchMatrix(matrix,target);
}