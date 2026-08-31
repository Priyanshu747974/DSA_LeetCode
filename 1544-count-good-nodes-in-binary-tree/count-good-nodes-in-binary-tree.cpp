class Solution {
public:
    int function(TreeNode* root, int curr, int pathMax) {
        if (!root) {
            return 0;
        }
        int isgood = 0;
        if (root->val >= pathMax) {
            isgood=1;
            curr++;
            pathMax = max(pathMax, root->val);
        }

        return isgood + function(root->left, curr, pathMax) +
               function(root->right, curr, pathMax);
    }

    int goodNodes(TreeNode* root) {
        return function(root, 0, root->val);
    }
};