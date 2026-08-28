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
public:
    bool dfs(TreeNode* root, int currentSum, int targetSum) {
        if (!root) return false;
       
        currentSum += root->val;
        
        if (!root->left && !root->right) {
            return currentSum == targetSum;
        }
        
        bool leftAns = dfs(root->left, currentSum, targetSum);
        bool rightAns = dfs(root->right, currentSum, targetSum);
        
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         return dfs(root, 0, targetSum);
    }
};