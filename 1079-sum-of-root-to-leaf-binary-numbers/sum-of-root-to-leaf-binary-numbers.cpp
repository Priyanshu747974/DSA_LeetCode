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
    vector<int> path(TreeNode* root, int binary) {
        vector<int> ans;
        if (!root)
            return ans;
        binary = binary * 2 + root->val;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(binary);
            return ans;
        }

        vector<int> left = path(root->left, binary);
        vector<int> right = path(root->right, binary);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }

    int sumRootToLeaf(TreeNode* root) {

        vector<int> bin = path(root, 0);

        int sum = 0;
        for (int x : bin) {
            sum += x;
        }
        return sum;
    }
};