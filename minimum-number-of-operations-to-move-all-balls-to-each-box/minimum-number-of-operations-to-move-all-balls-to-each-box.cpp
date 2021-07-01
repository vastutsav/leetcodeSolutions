class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sz = boxes.size();
        vector <int> ans(sz,0);
        
        int cnt = 0, pre = 0;
        for (int i = 0; i < sz; ++i) {
            ans[i] += pre;
            cnt = cnt + boxes[i] - '0';
            pre += cnt;
        }
        
        cnt = pre = 0;
        for (int i = sz-1; i >= 0; --i) {
            ans[i] += pre;
            cnt = cnt + boxes[i] - '0';
            pre += cnt;
        }
        return ans;
    }
};