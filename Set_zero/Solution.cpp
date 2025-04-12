#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> line(m),column(n);                  //采用两个数组来分别记录0的行列位置
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (matrix[i][j]==0){
                    line[i] = column[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (line[i]||column[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        cout << "[";                                             
        for (int i = 0; i < m; i++) {                        
            cout << "[";
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j]<<",";
            }
            cout << "]";
        }
        cout << "]";
    }
};

int main(){
    vector<vector<int>> matrix;
    int m{0},n{0};
    int x{0};
    cout<<"please enter m:\n";
    cin>>m;
    cout<<"please enter n:\n";
    cin>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<"please enter x:\n";
           cin>>x;
           matrix[i][j]=x; 
        }
    }
    Solution s1;
    s1.setZeroes(matrix);
}