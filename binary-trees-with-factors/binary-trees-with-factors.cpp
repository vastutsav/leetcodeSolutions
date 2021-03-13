class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long m = pow(10,9) + 7, ans = 0;
        sort(arr.begin(), arr.end());
        unordered_map <int, long> dp;
        for ( int i = 0; i < arr.size(); ++i ){
            dp[arr[i]] = 1;
            for ( int j = 0; j < i && arr[j] <= arr[i]/2; ++j){   
                if (arr[i]%arr[j]==0){
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i]/arr[j]])%m;
                }
            }
            ans = (ans + dp[arr[i]])%m;
        }
        return ans;
    }
};