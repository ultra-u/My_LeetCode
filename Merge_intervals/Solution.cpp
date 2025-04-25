#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());                        //先将区间按左端点排序
        vector<vector<int>> result;
        int start=intervals[0][0],end=intervals[0][1];                  //初始化一个区间
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>end){                                    //若当前区间的左端点大于第一个区间的右端点，则两个区间不重合
                result.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                if(intervals[i][1]>end){                                //后一个区间的右端点比前一个大
                    end=intervals[i][1];                                //更新右端点
                }
            }
        }
        result.push_back({start,end});                                  //加入最后一个区间
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
    int line{0}, column{0};
    cout << "please enter line:\n";
    cin >> line;
    cout << "please enter column:\n";
    cin >> column;
    vector<vector<int>> intervals;
    int interval{0};
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            cout<<"please enter interval:\n";
            cin>>interval;
            intervals[i][j] = interval;
        }
    }
    Solution s1;
    cout<<"the merge intervals is "<<s1.merge(intervals);
}