/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* function(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root== NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode*left=function(root->left,p,q);
        TreeNode*right=function(root->right,p,q);
            if(left != NULL && right != NULL) {
                return root;
            }

            if(left != NULL) {
                return left;
            }
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return function(root,p,q); 
    }
};