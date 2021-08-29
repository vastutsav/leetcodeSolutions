class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector < vector <int> > jobs;
        
        int sz = startTime.size();
        
        map <int, int> dp = {{0,0}};
        
        int ans = 0, tmp = 0;
        
        jobs.reserve(sz);
        
        for (int i = 0; i < sz; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        for (int i = 0; i < sz; ++i) {
            tmp = prev(dp.upper_bound(jobs[i][1]))->second + jobs[i][2];
            if (tmp > dp.rbegin()->second)
                dp[jobs[i][0]] = tmp;
        }
        
        return dp.rbegin()->second;
        
    }
};