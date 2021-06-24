class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1000000000 + 7;
        vector <vector <int>> dp (m, vector <int> (n,0));
        int count = 0;
        dp[startRow][startColumn] = 1;
        
        for (int x = 0; x < maxMove; ++x) {
            vector <vector <int>> temp (m, vector <int> (n,0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] != 0) { // means it can add to count if it is on edge
                        if ( i == 0 ) // top edge
                            count = (count + dp[i][j]) % MOD;
                        if ( i == m-1 ) // bottom edge
                            count = (count + dp[i][j]) % MOD;
                        if ( j == 0 ) // left edge
                            count = (count + dp[i][j]) % MOD;
                        if ( j == n-1 ) // right edge
                            count = (count + dp[i][j]) % MOD;
                    }
                    // creating dp for next iteration
                    temp[i][j] = ( 
                                    ((i == 0 ? 0:dp[i-1][j]) + (i == m-1 ? 0:dp[i+1][j])) % MOD
                                    +
                                    ((j == 0 ? 0:dp[i][j-1]) + (j == n-1 ? 0:dp[i][j+1])) % MOD
                    
                                )%MOD;
    
                }
            }
            dp = temp;
        }
        
        return count;
    }
};