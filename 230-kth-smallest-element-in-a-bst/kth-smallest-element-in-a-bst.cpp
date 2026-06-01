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
    int traverse(TreeNode* root,int & ans,int & cnt,int k){
        if(root==NULL){
            return 0;
        }
         traverse(root->left,ans,cnt,k);
         cnt++;
         if(cnt==k)ans=root->val;
         traverse(root->right,ans,cnt,k);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=0;
        ans= traverse(root,ans,cnt,k);
        return ans;
    }
};