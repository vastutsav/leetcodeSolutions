class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, sz = nums.size();
        if (!sz)
            return 0;
        while (j < sz) {
            if(nums[i] == nums[j])
                ++j;
            else
                nums[++i] = nums[j++];
        }
        return 1+i;
    }
};