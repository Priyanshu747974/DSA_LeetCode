/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& mp) {
    for(auto it : node->neighbors) {    
        if(mp.find(it) == mp.end()) {
            mp[it] = new Node(it->val);
            dfs(it, mp);
        }
        mp[node]->neighbors.push_back(mp[it]);
    }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
        Node* newGraph = new Node(node->val);
        mp[node] = newGraph;
        dfs(node, mp);
        return mp[node];
    }
};