class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int longest = 0;
        
        for (auto i:s) {
            int currLongest = 1;
            if (s.count(i-1))
                continue;
            while( s.count(i+currLongest)) 
                currLongest++;
            longest = max(longest, currLongest);
        }
        return longest;
    }
};