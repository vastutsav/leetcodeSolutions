class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1000000000 + 7;
        vector <int> a(n+1);
        vector <int> e(n+1);
        vector <int> i(n+1);
        vector <int> o(n+1);
        vector <int> u(n+1);
        
        a[0] = e[0] = i[0] = o[0] = u[0] = 1;
        for (int x = 1; x < n; ++x) {
            a[x] = ((e[x-1] + i[x-1])%MOD + u[x-1])%MOD;
            e[x] = (a[x-1] + i[x-1])%MOD;
            i[x] = (e[x-1] + o[x-1])%MOD;
            o[x] = i[x-1]%MOD;
            u[x] = (i[x-1] + o[x-1])%MOD;
        }
        return (((a[n-1] + e[n-1])%MOD + (i[n-1] + o[n-1])%MOD)%MOD + u[n-1])%MOD;
    }
};