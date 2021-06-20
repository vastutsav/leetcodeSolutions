class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp [1001][1001] = {{0}};
        int M = 1000000007;
        if ( k == 0 )
            return 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j==0)
                    dp[i][j] = 1;
                else {
                    int val = (dp[i-1][j] + M - (j-i>=0 ? dp[i-1][j-i]:0))%M;
                    dp[i][j] = (dp[i][j-1] + val) % M;
                }
            }
        }
        return (dp[n][k] + M - dp[n][k-1]) % M;
    }
};