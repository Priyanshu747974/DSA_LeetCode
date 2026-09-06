/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#,";
        // Preorder: Root, Left, Right
        return std::to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
TreeNode* deserializeHelper(std::stringstream& ss) {
        std::string token;
        std::getline(ss, token, ','); // Read up to the next comma
        
        if (token == "#") return nullptr;
        
        TreeNode* root = new TreeNode(std::stoi(token));
        
        // Rebuild in Preorder format
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));