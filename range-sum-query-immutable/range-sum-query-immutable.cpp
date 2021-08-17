class NumArray {
public:
    int sums[10001];
    NumArray(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; ++i){
            sums[i + 1] = sums[i] + nums[i]; 
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */