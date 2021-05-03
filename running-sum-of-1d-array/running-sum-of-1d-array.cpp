class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sz = nums.size();
        vector <int> ans (sz, 0);
        ans[0] = nums[0];
        for (int i = 1; i < sz; ++i) {
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
        
    }
};