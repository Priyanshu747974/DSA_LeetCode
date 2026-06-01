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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        // Special case: deleting root
        if (root->val == key) {
            if (root->left == NULL) {
                return root->right;
            }

            TreeNode* newRoot = root->left;
            TreeNode* next = newRoot;

            while (next->right != NULL) {
                next = next->right;
            }

            next->right = root->right;
            delete root;
            return newRoot;
        }

        TreeNode* prev = NULL;
        TreeNode* curr = root;

        // Search for the node
        while (curr != NULL && curr->val != key) {
            prev = curr;

            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // Key not found
        if (curr == NULL) {
            return root;
        }

        TreeNode* replacement;

        if (curr->left == NULL) {
            replacement = curr->right;
        }
        else {
            replacement = curr->left;

            TreeNode* next = replacement;
            while (next->right != NULL) {
                next = next->right;
            }

            next->right = curr->right;
        }

        // Connect parent to replacement
        if (prev->left == curr) {
            prev->left = replacement;
        } else {
            prev->right = replacement;
        }

        delete curr;
        return root;
    }
};