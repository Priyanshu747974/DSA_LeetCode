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
    int ans =0;
    int subtreesum(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftsum = subtreesum(root->left);
        int rightsum = subtreesum(root->right);
        return root->val + leftsum + rightsum;
    }
    int nodecount(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftcnt = nodecount(root->left);
        int rightcnt = nodecount(root->right);
        return 1 + leftcnt + rightcnt;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(root->val==subtreesum(root)/nodecount(root)){
            ans++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);

        return ans;
    }
};