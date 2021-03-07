class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0] - 1, prod = 0;
        int len = nums.size();
        for ( int i = 1; i < len; ++i )
        {
            if (prod < (nums[i] - 1) * mx)
                prod = (nums[i] - 1) * mx;
            if (mx < nums[i] - 1)
                mx = nums[i] - 1;
        }
        
        return prod;
    }
};

// 0 4 3 4