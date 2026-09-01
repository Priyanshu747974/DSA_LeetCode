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
    int function(TreeNode* root, long long curr, int targetSum, unordered_map<long long,int>&mpp){
        if(root==NULL){
            return 0;
        }
        curr = curr+root->val;

        int numpaths = mpp[curr - targetSum];

        mpp[curr]++;
        numpaths += function(root->left, curr,targetSum, mpp);
        numpaths += function(root->right, curr,targetSum, mpp);
        mpp[curr]--;
        return numpaths;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixMap;
        prefixMap[0] = 1;
        return function(root, 0, targetSum, prefixMap);
    }
};