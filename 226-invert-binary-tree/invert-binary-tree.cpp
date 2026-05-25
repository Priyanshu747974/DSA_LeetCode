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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node=root;
        if(node == NULL){
            return NULL;
        }
        TreeNode* left=invertTree(node->left);
        TreeNode* right=invertTree(node->right);
        
        root->left=right;
        root->right=left;
        
        return root;
    }
};