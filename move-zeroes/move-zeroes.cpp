class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size(), lastNonZero=0;
        
        for (int i = 0; i < sz; ++i) {
                if (nums[i] != 0)
                    swap(nums[i], nums[lastNonZero++]);
        }
    }
};