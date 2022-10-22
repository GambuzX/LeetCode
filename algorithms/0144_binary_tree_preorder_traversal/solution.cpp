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
    void visit(TreeNode* root, vector<int> &res) {
        if (root == nullptr) return;
        
        res.push_back(root->val);
        visit(root->left, res);
        visit(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        visit(root, res);   
        return res;        
    }
};