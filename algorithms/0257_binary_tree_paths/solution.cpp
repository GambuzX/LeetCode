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
    void helper(TreeNode* node, string curr, vector<string> &res) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(curr + "->" + to_string(node->val));
            return;
        }

        helper(node->left, curr + "->" + to_string(node->val), res);
        helper(node->right, curr + "->" + to_string(node->val), res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(to_string(root->val));
            return res;
        }

        helper(root->left, to_string(root->val), res);
        helper(root->right, to_string(root->val), res);
        return res;
    }
};