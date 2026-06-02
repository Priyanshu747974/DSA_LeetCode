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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i=1;i<preorder.size();i++){
            TreeNode* curr = root;
            int x = preorder[i];
            while(true){
                if(x<curr->val){
                    if(curr->left!=NULL)curr=curr->left;
                    else{
                        curr->left=new TreeNode(x);
                        break;
                    }   
                    
                }
                else{
                    if(curr->right!=NULL)curr=curr->right;
                    else{
                        curr->right=new TreeNode(x);
                        break;
                    }
                }
            }
        }
        return root;
    }
};