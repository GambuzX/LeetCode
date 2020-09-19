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
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> node_heights;
        calculate_node_heights(root, node_heights);
        return isBalanced(root, node_heights);
    }
    
    void calculate_node_heights(TreeNode* root, unordered_map<TreeNode*, int> &heights) {
        if (root == nullptr) return;
        
        calculate_node_heights(root->left, heights);
        calculate_node_heights(root->right, heights);  
        
        int left_height = root->left == nullptr ? 0 : heights.at(root->left);
        int right_height = root->right == nullptr ? 0 : heights.at(root->right);
        heights.insert(make_pair(root, max(left_height, right_height)+1));    
    }
    
    bool isBalanced(TreeNode* root, const unordered_map<TreeNode*, int> &heights) {
        if (root == nullptr) return true;
        
        int left = heights.find(root->left) != heights.end() ? heights.at(root->left) : 0;
        int right = heights.find(root->right) != heights.end() ? heights.at(root->right) : 0;
        
        return abs(left-right) > 1 ? false : isBalanced(root->left, heights) && isBalanced(root->right, heights);
    }
    
    
};