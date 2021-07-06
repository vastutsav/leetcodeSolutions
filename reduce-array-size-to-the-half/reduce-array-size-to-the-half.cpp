class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int hafCount, currCount, ans;
        unordered_map <int, int> umap;
        vector <int> freq;
        
        ans = 0;
        currCount = arr.size();
        hafCount = currCount/2;
        
        for (int i = 0; i < arr.size(); ++i) {
            auto itr = umap.find(arr[i]);
            if (itr == umap.end())
                umap[arr[i]] = 0;
            umap[arr[i]]++;
        }
        
        for (auto i:umap)
            freq.push_back(i.second);
        
        sort(freq.begin(), freq.end(),  greater<int>());
        
        for (auto f:freq) {
            currCount -= f;
            ++ans;
            if (currCount <= hafCount)
                break;
        }
        
        return ans;
    }
};