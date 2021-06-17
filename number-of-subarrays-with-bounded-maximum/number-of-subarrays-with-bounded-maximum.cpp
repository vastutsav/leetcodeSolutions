class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, start = 0, currSubsetCombs = 0;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            if (nums[i] >= left && nums[i] <= right) {
                currSubsetCombs = i - start + 1;
            }
            if (nums[i] > right) {
                start = i + 1;
                currSubsetCombs = 0;
            }
            ans += currSubsetCombs;
        }
        return ans;
    }
};