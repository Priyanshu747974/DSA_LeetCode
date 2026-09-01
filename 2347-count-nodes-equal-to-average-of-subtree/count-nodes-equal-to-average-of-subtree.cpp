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
    int count = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int totalSum = root->val + left.first + right.first;
        int totalCount = 1 + left.second + right.second;
        if (root->val == totalSum / totalCount) {
            count++;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};