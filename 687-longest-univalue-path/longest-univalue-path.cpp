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
    int global = 0;
    int traverse(TreeNode* root){
        if(!root)return 0;

        int left = max(0,traverse(root->left));
        if(root->left == nullptr || root->val != root->left->val) left = 0;

        int right = max(0,traverse(root->right));
        if(root->right == nullptr || root->val != root->right->val) right = 0;

        global = max(global , right+left+1);

        return 1+max(left,right);

    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        traverse(root);
        return global-1;
    }
};