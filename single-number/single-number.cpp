class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        for (int i = 0; i < sz; ++i)
            ans = ans^nums[i];
        
        return ans;
    }
};