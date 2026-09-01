/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> curr;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                for (int i = 0; i < node->children.size(); i++) {    
                    q.push(node->children[i]);
                }
                curr.push_back(node->val);
            }
            result.push_back(curr);
        }
        return result;
    }
};