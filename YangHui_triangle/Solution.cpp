#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i=0;i<numRows;++i){
            result[i].resize(i+1);                                      //初始化当前行的长度
            result[i][0]=result[i][i]=1;                                //边界值都为1
            for(int j=1;j<i;++j){
                result[i][j]=result[i-1][j]+result[i-1][j-1];
            }
        }
        return result;
    }
    friend ostream& operator<<(ostream& out,const vector<vector<int>>& result);
};

ostream& operator<<(ostream& out,const vector<vector<int>>& result){    //重载运算符"<<"
    out << "[";
    for (size_t i = 0; i < result.size(); ++i) {                        //注意result此时为二维向量
        out << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            out << result[i][j];
            if (j < result[i].size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        if (i < result.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main(){
    int numRows{0};
    cout<<"please enter numRows:\n";
    cin>>numRows;
    Solution s1;
    cout<<s1.generate(numRows);
}