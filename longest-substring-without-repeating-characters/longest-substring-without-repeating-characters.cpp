class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSub = 0, currSub=0;
        int len = s.length();
        int first = 0;

        unordered_map <char, int> umap;
        char ch;
        for (int i = 0; i < len; ++i)
        {
            ch = s[i];
            if (umap.find(ch) != umap.end())
            {
                first = max(umap[ch] + 1, first);
            }
            umap[ch] = i;
            maxSub = max(maxSub, i - first + 1);
            
            //cout << first << "<=>" << i << "<=>" << maxSub <<endl;
        }
        return maxSub;
    }
};