class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector <pair<int, int>> eng;
        for (int i = 0; i < n; ++i)
            eng.emplace_back(efficiency[i], speed[i]);
        
        sort(eng.rbegin(), eng.rend());
        
        priority_queue <int, vector<int>, greater<int>> minH;
        
        long speedSum = 0, ans = 0;
        
        for (auto [currEff, currSpd]:eng) {
            
            if (minH.size() > k-1){
                speedSum -= minH.top();
                minH.pop();
            }
            speedSum += currSpd;
            minH.push(currSpd);
            
            ans = max(ans, speedSum*currEff);
        }
        
        return ans % (int) (1e9 + 7);
    }
};