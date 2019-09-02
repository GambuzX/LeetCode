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
public:
    bool isValidBST(TreeNode* root) {
        
        if (root == NULL) return true;
        
        queue<TreeNode*> visited;
        inOrderVisit(root, visited);
        
        int prev = visited.front()->val;
        visited.pop();
        while(!visited.empty()){
            int & curr = visited.front()->val;
            if (curr <= prev) return false;
            prev = curr;
            visited.pop();
        }
        
        return true;
    }
    
    void inOrderVisit(TreeNode* root, queue<TreeNode*> & visited) {
        
        if (root->left != NULL) inOrderVisit(root->left, visited);
        
        visited.push(root);
        
        if (root->right != NULL) inOrderVisit(root->right, visited);        
    }
};