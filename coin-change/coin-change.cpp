class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int a[10001]={0};
        int t = 0;
        for (int i = 1; i <= amount; ++i)
        {
            a[i] = INT_MAX-1;
            for (auto itr = coins.begin(); itr != coins.end(); ++itr)
            {
                if ((t=i-*itr) >= 0)
                {
                    a[i]=min(a[i],a[t]+1);
                }
            }
            // cout << i << " - "<< a[i] << endl;
        }
        return (a[amount]==INT_MAX-1)?-1:a[amount];
    }
};