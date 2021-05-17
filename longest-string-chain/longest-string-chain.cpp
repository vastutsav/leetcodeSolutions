class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), 
             [](const string& s1, const string& s2) {return s1.length() < s2.length();});
        unordered_map <string, int> dp;
        int res = 0;
        for (string w:words){
            for (int i=0, e=w.length(); i < e; ++i) {
                string w2 = w.substr(0,i) + w.substr(i+1);
                if (dp.find(w2) == dp.end()) {
                    dp[w] = max(dp[w], 1);
                } else {
                    dp[w] = max(dp[w], dp[w2] + 1);
                }
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};