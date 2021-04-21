class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> ans(triangle.back());
        for (int i = n-2; i >= 0; i--) 
        {
            for (int j = 0; j <= i; j++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                ans[j] = min(ans[j], ans[j+1]) + triangle[i][j]; 
            }
        }
         
        return ans[0];
    }
};