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
        
        if (root == NULL) return "[]";
        
        string result = "[";
        
        /* Level visit */
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            TreeNode* next = nodes.front();
            nodes.pop();
            
            if (next == NULL) {
                result += "n,";
            }
            else {                
                result += to_string(next->val) + ",";

                nodes.push(next->left);
                nodes.push(next->right);
            }
        }
        
        /* Remove nulls at end */
        int end_index = result.length()-2;
        while(result[end_index] == 'n') end_index -= 2;
        
        return result.substr(0, end_index+1) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if (data.length() == 2) return NULL;
        
        // array of strings
        vector<string> treeNodes;        
        istringstream iss(data.substr(1, data.length()-2));
        string str;
        while(getline(iss, str, ',')) treeNodes.push_back(str);
        
        TreeNode * head = new TreeNode(stoi(treeNodes[0]));
        queue<TreeNode*> insertQueue;
        insertQueue.push(head);
        
        int curr_node = 1;
        while(curr_node < treeNodes.size()) {
            TreeNode * curr = insertQueue.front();
            insertQueue.pop();
            
            string & next = treeNodes[curr_node++];
            if (next != "n") {
                curr->left = new TreeNode(stoi(next));
                insertQueue.push(curr->left);
            }
            
            if (curr_node == treeNodes.size()) break;
            
            next = treeNodes[curr_node++];
            if (next != "n") {
                curr->right = new TreeNode(stoi(next));  
                insertQueue.push(curr->right);              
            }            
        }
        
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));