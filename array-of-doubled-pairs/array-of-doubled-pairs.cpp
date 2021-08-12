class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> umap;
        vector <int> vals;
        
        
        for (auto a : arr) {
            umap[a]++;
        }
        
        for (auto itr = umap.begin(); itr != umap.end(); ++itr) {
            vals.push_back(itr->first);
        }
        
        sort (vals.begin(), vals.end(), [](int a , int b) { return abs(a) < abs(b); });
        
        for (auto itr = vals.begin(); itr != vals.end(); ++itr) {
            if (umap[*itr] > umap[(*itr) * 2])
                return false;
            
            umap[(*itr) * 2] -= umap[*itr];
        }
        
        
        return true;
        
    }
};