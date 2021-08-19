class Solution {
    bool isValid(const string& str){
        if (str[0] == '0')
            return false;
        int n = stoi(str);
        if (n < 1 || n > 26)
            return false;
        
        return true;
    }
public:
    int numDecodings(string s) {
        const int sz = s.size();
        vector <int> dp(sz+1, 0);
        string tmp;
        
        dp[sz] = 1;
        for (int i = sz-1; i>=0; --i) {
            tmp.clear();
            tmp = tmp + s[i];
            
            if (isValid(tmp)) {
                dp[i] += dp[i+1];
            }
            
            if ((i+1) >= sz)
                continue;
            
            tmp = tmp + s[i+1];
            if (isValid(tmp)) {
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};