class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> umap;
        vector <vector<string>> ans;
        for (string& w:strs) {
            string tmp = w;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(w);
        }
        ans.reserve(umap.size());
        for (auto& item:umap) {
            ans.push_back(move(item.second));
        }
        return ans;
        
    }
};
