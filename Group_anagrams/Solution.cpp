#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagram;                       //建立一个哈希表，键是字符串，值是字符串向量
        for(string& str:strs){
            string sortStr=str;
            sort(sortStr.begin(),sortStr.end());                            //对字符串进行排序
            anagram[sortStr].push_back(str);                                //使用排序后的字符串作为键
        }
        vector<vector<string>> result;
        for(auto& pair:anagram){
            result.push_back(pair.second);                                  //将每组异位词加入结果
        }
        return result;
    }
    friend ostream& operator<<(ostream& out,const vector<vector<string>>& result);
};

ostream& operator<<(ostream& out,const vector<vector<string>>& result){    //重载运算符"<<"
    out << "[";
    for (size_t i = 0; i < result.size(); ++i) {                        
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
    vector<string> strs;
    string str;
    int size{0};
    cout<<"please enter size:\n";
    cin>>size;
    cin.ignore();                                                       // 清除缓冲区中的换行符
    for(int i=0;i<size;i++){
        cout<<"please enter str:\n";
        getline(cin,str);
        strs.push_back(str);
    }
    Solution s1;
    cout<<s1.groupAnagrams(strs);
}