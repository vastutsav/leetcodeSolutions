class Solution {

private:
    int getMedian(vector<int>& arr) {
        return arr[(arr.size() - 1)/2];
    }
    
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = getMedian(arr);
        sort(arr.begin(), arr.end(), [m](const auto a, const auto b) {
            if (abs(a-m) > abs(b-m)) {
                return true;
            }
            else if (abs(a-m) == abs(b-m) && a > b) {
                return true;
            }
            else {
                return false;
            }
        });
        
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};