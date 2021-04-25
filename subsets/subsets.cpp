class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> lis;
        int n = nums.size();
        for (int i = 0; i < (1<<n); ++i){
            vector<int>tmp; 
            for (int j = 0; j < n; ++j){
                if (i & (1<<j)) {
                    // cout << nums[j] << " ";
                    tmp.push_back(nums[j]);
                }
            }
            lis.push_back(tmp);
        }
        
        return lis;
    }
};