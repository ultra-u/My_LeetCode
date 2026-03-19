#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;     //存储腐烂橘子坐标
        int freshcount{0},minutes{0};
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){          //统计新鲜橘子的数量
                    freshcount++;
                }else if(grid[i][j]==2){    //找出腐烂橘子的坐标位置
                    q.push({i,j});
                }
            }
        }
        if(freshcount==0) return 0;
        while(!q.empty()){
            int size=q.size();
            bool rotted=false;              //标记这一轮是否有橘子腐烂
            for(int i=0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int d=0;d<4;d++){       //检查四个方向
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==1){      //判断是否在范围内且是新鲜橘子
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        freshcount--;
                        rotted=true;
                    }
                }
            }
            if(rotted){
                minutes++;
            }
        }
        return freshcount==0?minutes:-1;
    }
};

int main(){
    int line{0},column{0};
    vector<vector<int>> grid;
    cout<<"please enter line:\n";
    cin>>line;
    cout<<"please enter column:\n";
    cin>>column;
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            cout<<"please enter val:\n";
            cin>>grid[i][j];
        }
    }
    Solution s;
    cout<<s.orangesRotting(grid);
}