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
    vector<bool> bfs(TreeNode* root, vector<bool> ans) {
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        int prev;
        while (!q.empty()) {
            int size = q.size();
            bool levelans = true;
            cnt++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (cnt % 2 == 0 && (node->val) % 2 != 0) {
                    levelans = false;
                }
                if (cnt % 2 != 0 && (node->val) % 2 == 0) {
                    levelans = false;
                }
                if (i > 0) {
                    if (cnt % 2 != 0 && node->val <= prev)
                        levelans = false;

                    if (cnt % 2 == 0 && node->val >= prev)
                        levelans = false;
                }

                prev = node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            ans.push_back(levelans);
        }
        return ans;
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<bool> ans;
        ans = bfs(root, ans);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == false) {
                return false;
                break;
            }
        }
        return true;
    }
};