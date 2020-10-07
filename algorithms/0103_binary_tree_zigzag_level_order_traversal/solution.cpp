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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        
        vector<vector<int>> solution;
        zigzagHelper({root}, true, solution);
        return solution;
    }
    
    void zigzagHelper(vector<TreeNode*> currLevelNodes, bool leftToRight, vector<vector<int>>& solution) {
        if(currLevelNodes.empty()) return;
        
        vector<int> currLevelValues = vector<int>(currLevelNodes.size(), 0);
        vector<TreeNode*> nextLevelNodes;
        
        for (int i = 0 ; i < currLevelNodes.size(); i++) {
            TreeNode* curr = currLevelNodes[i];

            int index = leftToRight ? i : currLevelNodes.size() - i - 1; 
            currLevelValues[index] = curr->val;
            if(curr->left != NULL) nextLevelNodes.push_back(curr->left);
            if(curr->right != NULL) nextLevelNodes.push_back(curr->right);                
        }
        
        solution.push_back(currLevelValues);
        zigzagHelper(nextLevelNodes, !leftToRight, solution);
    }
};