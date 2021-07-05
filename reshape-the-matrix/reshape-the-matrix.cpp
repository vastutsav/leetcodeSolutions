class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector <vector <int>> ans (r, vector<int> (c));
        int x = 0;
        int origMatRow = mat.size();
        int origMatCol = mat[0].size();
        if (origMatRow * origMatCol != r * c)
            return mat;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                ans[i][j] = mat[x/origMatCol][x%origMatCol];
                ++x;
            }
        }
        return ans;
    }
};