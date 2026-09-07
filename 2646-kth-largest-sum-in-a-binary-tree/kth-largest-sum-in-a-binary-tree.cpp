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
    vector<long long> bfs(TreeNode* root,vector<long long>& ans){
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long levelsum=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                levelsum +=node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(levelsum);
            levelsum = 0;
        }
        return ans;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        bfs(root,ans);
        int levels = ans.size();
        sort(ans.begin(),ans.end());
        if(levels<k){
            return -1;
        }
        return ans[ans.size()-k];
    }
};