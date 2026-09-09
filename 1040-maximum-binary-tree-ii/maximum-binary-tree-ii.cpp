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
    void inorder(TreeNode* root,vector<int>& a){
        if(!root){
            return;
        }
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    TreeNode* construct(vector<int>& nodes,int start, int end){
        if(start>end){
            return NULL;
        }
        int maxi = start;
        for(int i=start+1;i<=end;i++){
            if(nodes[i]>nodes[maxi]){
                maxi = i;
            }
        }
        TreeNode* root = new TreeNode(nodes[maxi]);
        int mid  = maxi;
        root->left = construct(nodes,start,mid-1);
        root->right = construct(nodes,mid+1,end);

        return root;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> a;
        inorder(root,a);
        a.push_back(val);
        return construct(a,0,a.size()-1);
    }
};