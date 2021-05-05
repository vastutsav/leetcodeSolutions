class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        vector <int> dp (sz, 1001);
        dp[0] = 0;
        for (int i = 0; i < sz - 1; ++i){
            for (int j = 1; j <= nums[i] && j + i < sz ; ++j) {
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        
        return dp[sz-1];
    }
};