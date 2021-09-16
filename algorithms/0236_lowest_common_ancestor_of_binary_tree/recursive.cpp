/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* solution;
public:
    bool findNode(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return false;
        
        bool l = findNode(root->left, p, q);
        bool r = findNode(root->right, p, q);
        bool m = root == p || root == q;
        
        if (l + r + m >= 2) solution = root;
        
        return l || r || m;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solution = NULL;
        findNode(root, p, q);
        return solution;
    }
};