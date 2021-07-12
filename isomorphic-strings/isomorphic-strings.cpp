class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> umap;
        unordered_set <char> uset;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            if (umap.find(t[i]) == umap.end()) {
                if (uset.find(s[i]) == uset.end()) {
                    umap[t[i]] = s[i];
                    uset.insert(s[i]);
                }
                else {
                    return false;
                }
            }
            t[i] = umap[t[i]];
        }
        return t==s;
        
    }
};