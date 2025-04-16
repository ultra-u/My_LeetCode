#include <iostream>
#include <vector>
using namespace std;

class Solution {                                    //采用DFS，DFS的次数即为岛屿数量
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();                       //获取行数
        int nc = grid[0].size();                    //获取列数
        grid[r][c] = '0';                           //将当前访问的位置标记为 '0'，表示已经访问过
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);         //递归搜索上方
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);         //递归搜索下方
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);         //递归搜索左边
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);         //递归搜索右边
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};

int main(){
    int nr;
    cout<<"Please enter the number of rows of the grid:\n";
    cin >> nr;
    vector<vector<char>> grid(nr, vector<char>(0));
    cout<<"Please enter the elements of each line, separated by Spaces, and press Enter at the end of each line:\n";
    for (int i = 0; i < nr; ++i) {
        grid[i].resize(0);
        string line;
        getline(cin, line);
        for (char& c : line) {
            if (c != ',') grid[i].push_back(c - '0');
        }
    }
    int num_islands = Solution().numIslands(grid);
    cout<<"Number of islands:"<<num_islands;
}