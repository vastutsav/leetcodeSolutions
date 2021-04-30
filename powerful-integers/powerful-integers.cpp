class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set <int> uset;
        
        for (int i = 1; i <= bound; i = i*x) {
            for (int j = 1; i+j <= bound; j = j*y) {
                uset.insert(i+j);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        
        return vector<int> (uset.begin(), uset.end());
    }
};