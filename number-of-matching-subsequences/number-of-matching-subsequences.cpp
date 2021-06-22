class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int i = 0;
        int ans = 0;
        vector <vector <int>> lst(26);
        for (auto a:s) {
            lst[a - 'a'].push_back(i);
            i++;
        }
        
        for (auto w:words) {
            int idx = -1;
            bool found = true;
            for (auto c:w) {
                int q = c - 'a';
                auto it = upper_bound(lst[q].begin(), lst[q].end(), idx);
                if (it == lst[q].end()){
                    found = false;
                    break;
                }
                else
                {
                    idx = *it;
                }
            }
            if (found)
            {
                ans++;
            }
        }
        return ans;
    }
};