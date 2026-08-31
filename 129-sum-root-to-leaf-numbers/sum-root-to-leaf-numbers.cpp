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
    int function(TreeNode* root, int curr){
        if(!root){
            return 0;
        }
        curr = curr*10 + root->val;

        if(!root->left && !root->right){
            return curr;
        }

        return function(root->left,curr) + function(root->right, curr);

    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        int curr =0;
        curr = function(root, 0);
        return curr;
    }
};