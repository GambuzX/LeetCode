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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        queue<pair<TreeNode*, int>> toVisit;
        toVisit.push({root, 1});        
        
        while(!toVisit.empty()) {
            pair<TreeNode*, int> next = toVisit.front();
            toVisit.pop();
            
            if (next.first == NULL) continue;
            
            if (next.second > res.size())
                res.push_back({next.first->val});
            else
                res[next.second-1].push_back(next.first->val);
            
            toVisit.push({next.first->left, next.second+1});
            toVisit.push({next.first->right, next.second+1});
        }
        
        return res;
    }
};