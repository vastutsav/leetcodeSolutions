class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int s = 0;
        for (auto n: nums)
            s=s + cnt[n]++;
        
        return s;
    }

};