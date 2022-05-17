class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u_map;
        int need;
        for (int i = 0; i < nums.size(); ++i) {
            need = target - nums[i];
            if (u_map.find(need) != u_map.end()) {
                return {i, u_map[need]};
            }
            u_map[nums[i]] = i;
        }
        return {0,0};
    }
};