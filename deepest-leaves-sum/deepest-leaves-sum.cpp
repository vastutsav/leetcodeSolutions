/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int dfsLevel(TreeNode* root){
        int m = 0;
        
        if (root->left != NULL)
            m = max(m, 1 + dfsLevel(root->left)); 

        if (root -> right != NULL)
            m = max(m, 1 + dfsLevel(root->right));

        return m;
        
    }
    
    
    int dfsSum(TreeNode* root, int curr, int fin) {
        if(root == NULL)
            return 0;
        
        if (curr == fin)
            return root->val;
        
        return dfsSum(root->left, curr+1, fin) + dfsSum(root->right, curr+1, fin);
        
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        return dfsSum(root, 0, dfsLevel(root));
    }
};