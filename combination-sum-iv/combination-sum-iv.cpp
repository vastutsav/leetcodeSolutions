class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector <unsigned int> dp (target+1,0);
        sort (nums.begin(), nums.end());
        
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] > i)
                    break;
                
                if (i == nums[j]) {
                    ++dp[i];
                }
                else {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};