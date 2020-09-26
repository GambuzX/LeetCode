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
    int minDepth(TreeNode* root) {
        return root == nullptr ? 0 : minDepth(root, 1);
    }
    
    int minDepth(TreeNode* root, int depth) {
        if(root == nullptr) return INT_MAX;
        
        if (root->left == nullptr && root->right == nullptr) 
            return depth;
        
        return min(minDepth(root->left, depth+1), minDepth(root->right, depth+1));
    }
};