class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto n: nums)
            ++cnt[n];
        return accumulate(begin(cnt)
                        , std::end(cnt)
                        , 0
                        , [] (int value, const std::map<int, int>::value_type& p)
                           { return value + p.second*(p.second-1)/2; });
    }

};