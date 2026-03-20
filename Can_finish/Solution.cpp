#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(const auto& pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        vector<int> queue;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                queue.push_back(i);
            }
        }
        int count{0};
        while(!queue.empty()){
            int course=queue.back();
            queue.pop_back();
            count++;
            for(int next:graph[course]){
                indegree[next]--;
                if(indegree[next]==0){
                    queue.push_back(next);
                }
            }
        }
        return count==numCourses;
    }
};

int main(){
    vector<vector<int>> prerequistites;
    int numCourses{0},line{0},column{0};
    cout<<"please enter numCourses:\n";
    cin>>numCourses;
    cout<<"please enter line:\n";
    cin>>line;
    cout<<"please enter column:\n";
    cin>>column;
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            cout<<"please enter val:\n";
            cin>>prerequistites[i][j];
        }
    }
    Solution s;
    cout<<s.canFinish(numCourses,prerequistites);
}