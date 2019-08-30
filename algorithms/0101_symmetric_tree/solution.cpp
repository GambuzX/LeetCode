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
    bool isSymmetric(TreeNode* root) {
        vector<int> v1, v2;
        v1 = left_dfs(root);
        v2 = right_dfs(root);
        return std::equal(v1.begin(), v1.end(), v2.begin());
    }
    
    vector<int> left_dfs(TreeNode* root) {
        vector<int> ret;
        left_dfs(root, ret);
        return ret;
    }
    
    void left_dfs(TreeNode* curr, vector<int>& vec) {
        if (curr == NULL) {
            vec.push_back(-1);
            return;
        }
        vec.push_back(curr->val);
        left_dfs(curr->left, vec);
        left_dfs(curr->right, vec);
    }
    
    vector<int> right_dfs(TreeNode* root) {
        vector<int> ret;
        right_dfs(root, ret);
        return ret;
    }
    
    void right_dfs(TreeNode* curr, vector<int>& vec) {
        if (curr == NULL) {
            vec.push_back(-1);
            return;
        }
        vec.push_back(curr->val);
        right_dfs(curr->right, vec);
        right_dfs(curr->left, vec);
    }
};