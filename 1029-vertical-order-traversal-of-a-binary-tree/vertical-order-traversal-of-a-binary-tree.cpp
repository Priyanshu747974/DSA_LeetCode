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
    map<int,vector<pair<int,int>>> mpp;
    void allotxy(TreeNode* root,int x,int y){
        vector<pair<int,int>> v;
        TreeNode* node=root;
        if(node==NULL){
            return;
        }
        mpp[y].push_back({x,node->val});
        allotxy(node->left,x+1,y-1);
        allotxy(node->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        int x=0;
        int y=0;
        allotxy(root,x,y);
        for(auto &it : mpp){
            vector<int> samey;
            sort(it.second.begin(), it.second.end());
            for(auto p : it.second){
                samey.push_back(p.second);
            }
            ans.push_back(samey);
        }
        return ans;
    }
};