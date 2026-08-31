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
    void function(TreeNode * root, vector<int>& v){
        if(root==NULL){
            return;
        }
        
        function(root->left,v);
        v.push_back(root->val);
        function(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        function(root1, list1);
        function(root2, list2);

        vector<int> result;
        int i = 0, j = 0;
        int n1 = list1.size(), n2 = list2.size();

        while (i < n1 && j < n2) {
            if (list1[i] <= list2[j]) {
                result.push_back(list1[i++]);
            } else {
                result.push_back(list2[j++]);
            }
        }
        while (i < n1) result.push_back(list1[i++]);
        while (j < n2) result.push_back(list2[j++]);

        return result;
    }
};