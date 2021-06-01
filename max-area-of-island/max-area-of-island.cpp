#define UNVISITED_LAND 1
#define VISITED_LAND 2

class Solution {
    int dir [4][4] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    bool isValid(vector<vector<int>>& grid, const int x, const int y) {
        if (x < 0
          ||x >= grid.size()
          ||y < 0 
          ||y >= grid[0].size()
          ||grid[x][y] != UNVISITED_LAND)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, const int& x, const int& y, int& currVal) {
        if (isValid(grid, x, y) && grid[x][y] == UNVISITED_LAND) {
            currVal++;
            grid[x][y] = VISITED_LAND;
            for (int i = 0; i < 4; ++i) {
                if (isValid(grid, x+dir[i][0], y+dir[i][1])) {
                    dfs(grid, x+dir[i][0], y+dir[i][1], currVal);
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int currVal = 0, mxxVal = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                currVal = 0;
                dfs(grid, i, j, currVal);
                mxxVal = max(mxxVal,currVal);
            }
        }
     
        return mxxVal;
    }
};