class Solution {
bool isValid(vector<vector<int>>& obstacleGrid, int i, int j) {
    if (i < 0)
        return false;
    
    if (j < 0)
        return false;
    
    if (obstacleGrid[i][j] == 1)
        return false;
    
    return true;
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        
        obstacleGrid[0][0] = -1;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (isValid(obstacleGrid, i, j)) {
                    obstacleGrid[i][j] += isValid(obstacleGrid, i-1, j)?(obstacleGrid[i-1][j]):0;
                    obstacleGrid[i][j] += isValid(obstacleGrid, i, j-1)?(obstacleGrid[i][j-1]):0;
                }
            }
        }

        return -obstacleGrid[m-1][n-1];
    }
};