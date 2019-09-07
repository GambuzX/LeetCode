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
    int max_sum = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        
        maxSum(root);
        return this->max_sum;        
    }
    
    int maxSum(TreeNode* node) {
        
        if (node == NULL) return 0;
        
        // reached base
        if (node->left == NULL && node->right == NULL) {
            this->max_sum = max(this->max_sum, node->val);
            return node->val;
        }
        
        int left_max = maxSum(node->left);
        int right_max = maxSum(node->right);
        
        int curr_sum = node->val;
        int total = curr_sum + left_max + right_max;
        
        if (left_max > 0 && left_max > right_max) curr_sum += left_max;
        if (right_max > 0 && right_max > left_max) curr_sum += right_max;
        
        this->max_sum = max(this->max_sum, curr_sum);
        this->max_sum = max(this->max_sum, total);
        
        return curr_sum;
        
    }
};