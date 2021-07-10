class Solution {
    int  isValid(string s, int sz){
        
        if (s[0] != '*') {
            int a = stoi(s);
            if (sz > 1 && a < 10)
                return false;
            if ( a < 1 || a > 26)
                return false;
        }
        
        return true;
    }
public:
    int numDecodings(string s) {
        int sz = s.size();
        int di, si;
        const int MOD = 10e8 + 7;
        vector <long> dp (sz+1,0);
        dp[0] = 1;
        
        for (di = 1,si = 0; di <= sz; ++di, ++si)
        {
            if (s[si] == '*') {
                dp[di] = (dp[di-1] * 9)%MOD;
                if (si != 0) {
                    if (s[si-1] == '1') {
                        dp[di] += (dp[di-2] * 9)%MOD;
                    } else if (s[si-1] == '2') {
                        dp[di] += (dp[di-2] * 6)%MOD;
                    } else if (s[si-1] == '*') {
                        dp[di] += (dp[di-2] * 15)%MOD;
                    }
                }
            }
            else {
                if (isValid(s.substr(si,1), 1))
                    dp[di] = (dp[di] + dp[di-1])%MOD;
                if (si > 0) {
                    if (s[si-1] == '*') {
                        if (s[si] >= '0' && s[si] <= '6')
                            dp[di] = (dp[di] + dp[di-2] * 2)%MOD;
                        else
                            dp[di] = (dp[di] + dp[di-2])%MOD;
                    } else {
                        if (isValid(s.substr(si-1,2), 2))
                            dp[di] = (dp[di] + dp[di-2])%MOD;
                    }
                }
            }
        }
        return dp[di-1]%MOD;
    }
};