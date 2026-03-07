#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution{
public: 
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
        cout << "[";                                             
        for (int i = 0; i < n; i++) {                        
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
    cout<<"the rotated matrix is:\n";
    s1.rotate(matrix);
}