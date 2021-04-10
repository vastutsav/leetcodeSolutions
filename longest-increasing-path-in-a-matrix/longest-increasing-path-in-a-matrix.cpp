class Solution {

private:
    int dirs[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int memo [200][200] = {};
    int maxI = 0;
    int maxJ = 0;
    
    bool isValid(vector<vector<int>>& matrix, int p, int q, int i, int j) {
        if (i < 0 || i >= maxI)
            return false;
        
        if (j < 0 || j >= maxJ)
            return false;
        
        if (matrix[p][q] >= matrix[i][j])
            return false;
        
        return true;
    }
    
    int dfs (vector<vector<int>>& matrix, int i, int j){
        if (memo[i][j] != 0)
            return memo[i][j];
        
        for (auto d:dirs){
            int ii = i + d[0];
            int jj = j + d[1];
            if (isValid(matrix, i, j, ii, jj)) {
                memo[i][j] = max(memo[i][j] , dfs(matrix, ii, jj));
            }
        }
        return ++memo[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxI = matrix.size();
        if (maxI == 0) return 0;
        
        maxJ = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < maxI; ++i) {
            for (int j = 0; j < maxJ; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};