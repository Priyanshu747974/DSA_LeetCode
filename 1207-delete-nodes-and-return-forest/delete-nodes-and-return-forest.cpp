class Solution {
public:

    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<TreeNode*> ans;
    unordered_set<int> st;

    TreeNode* solve(TreeNode* root) {

        if(root == NULL)
            return NULL;

        root->left = solve(root->left);
        root->right = solve(root->right);

        if(st.count(root->val)) {

            if(root->left)
                ans.push_back(root->left);

            if(root->right)
                ans.push_back(root->right);

            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        for(int x : to_delete)
            st.insert(x);

        root = solve(root);
        if(root)
            ans.push_back(root);

        return ans;
    }
};