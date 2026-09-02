/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root, int depth, int x, TreeNode* parent) {
        if (!root) {
            return {-1,NULL};
        }
        if (root->val == x) {
            return {depth,parent};
        }
        auto left = dfs(root->left, depth + 1, x,root);

        if (left.first != -1) {
            return left;
        }

        return dfs(root->right, depth + 1, x,root);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        auto a = dfs(root, 0, x, nullptr);
        auto b = dfs(root, 0, y, nullptr);

        return a.first == b.first && a.second != b.second;
    }
};