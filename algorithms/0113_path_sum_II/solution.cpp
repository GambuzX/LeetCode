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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        dfs(root, sum, paths, vector<int>());
        return paths;
    }
    
    bool isLeaf(TreeNode * node) {
        return node->left == NULL && node->right == NULL;
    }
    
    int vecSum(vector<int> & v) {
        int total = 0;
        for(int i : v) total += i;
        return total;
    }
    
    void dfs(TreeNode * node, int sum, vector<vector<int>> & paths, vector<int> prev) {
        if (node == NULL) return;
        
        prev.push_back(node->val);
        int currSum = vecSum(prev);
        if (isLeaf(node)) {
            if (currSum == sum) paths.push_back(prev);
            return;
        }
        
        //if (currSum > sum) return;
        dfs(node->left, sum, paths, prev);
        dfs(node->right, sum, paths, prev);
    }
};