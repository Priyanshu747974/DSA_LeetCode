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
    TreeNode* checkInversion(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        TreeNode* left= checkInversion(root->left);
        TreeNode* right= checkInversion(root->right);

        root->left=right;
        root->right=left;

        return root;
    }
    TreeNode* createDuplicate(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(root->val);

        newNode->left = createDuplicate(root->left);
        newNode->right = createDuplicate(root->right);

        return newNode;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        if(p->val == q->val){
            return isSameTree(p->left,q->left) &&
            isSameTree(p->right,q->right);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* tree =createDuplicate(root);
        checkInversion(root);
        return isSameTree(root,tree);
    }
};