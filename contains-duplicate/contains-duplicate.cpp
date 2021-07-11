class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> uset;
        int sz = nums.size();
        
        for (int i = 0; i < sz; ++i) {
            if (uset.find(nums[i]) != uset.end())
                return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};