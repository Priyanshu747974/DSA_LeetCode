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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lefth=height(root->left);
        int righth=height(root->right);
        return 1 + max(lefth,righth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);

        int leftdepth = diameterOfBinaryTree(root->left);
        int rightdepth = diameterOfBinaryTree(root->right);
        return max({leftdepth,rightdepth,left+right});
    }
};