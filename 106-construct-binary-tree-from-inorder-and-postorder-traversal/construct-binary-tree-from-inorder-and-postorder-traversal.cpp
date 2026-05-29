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
    TreeNode* build(vector<int>& postorder, int& postIndex,
                    int inStart, int inEnd,
                    map<int,int>& mpp) {
        
        if(inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int inRoot = mpp[root->val];

        // build right subtree first
        root->right = build(postorder, postIndex,
                            inRoot + 1, inEnd, mpp);

        // build left subtree
        root->left = build(postorder, postIndex,
                           inStart, inRoot - 1, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int> mpp;

        for(int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return build(postorder, postIndex,
                     0, inorder.size() - 1,
                     mpp);
    }
};