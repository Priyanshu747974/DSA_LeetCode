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
    int function(TreeNode* root, int maxi,int mini){
        if(!root){
            return maxi-mini;
        }

        maxi = max(maxi,root->val);
        mini = min(mini,root->val);

        int diffleft = function(root->left,maxi,mini);
        int diffright = function(root->right,maxi,mini);

        return max(diffleft,diffright);
    }
    int maxAncestorDiff(TreeNode* root) {
        return function(root,-1e9,1e9);
    }
};