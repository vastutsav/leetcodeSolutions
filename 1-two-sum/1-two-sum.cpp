class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u_map;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];
            if (u_map.find(need) != u_map.end()) {
                result.push_back(i);
                result.push_back(u_map[need]);
                return result;
            }
            u_map[nums[i]] = i;
        }
        return result;
    }
};