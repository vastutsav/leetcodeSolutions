class Solution {
    public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1) 
            return 0;
        int cMax = 0;
        vector<int> dp(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = (i-2) >= 0 ? (dp[i-2] + 2) : 2;
                    cMax = max(dp[i],cMax);
                }
                else{
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                        dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >= 0)?dp[i-dp[i-1]-2]:0);
                        cMax = max(dp[i],cMax);
                    }
                }
            }
        }
        return cMax;
    }
};