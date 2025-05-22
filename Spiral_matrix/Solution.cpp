#include <iostream>
#include <vector>
using namespace std;

class Solution {                                                //四指针
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=n-1,top=0,bottom=m-1;                  //设置初始值(左右上下)
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++){                       //从左到右，顶部一层遍历完往下移一位，top++
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){                       //从上到下，遍历完右侧往左移一位，right--
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){                   //从右到左，判断top <= bottom，即是否上下都走完了。遍历完底部上移，bottom--
                    result.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){                   //从下到上，判断left <= right，遍历完左侧右移，left++
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
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
    vector<vector<int>> matrix;
    int line{0},column{0},num{0};
    cout<<"please enter line:\n";
    cin>>line;
    cout<<"please enter column:\n";
    cin>>column;
    matrix.resize(line,vector<int>(column));
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            cout<<"please enter num:\n";
            cin>>num;
            matrix[i][j]=num;
        }
    }
    Solution s1;
    cout<<"The elements of the clockwise spiral return matrix are:"<<s1.spiralOrder(matrix);
}