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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        
        int mid = nums.size()/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = insertInRange(nums, 0, mid-1);
        root->right = insertInRange(nums, mid+1, nums.size()-1);
        return root;        
    }
    
    TreeNode* insertInRange(vector<int>&nums, int lower, int upper) {
        if (lower > upper) return NULL;
        
        int mid = (lower+upper)/2;
        TreeNode * new_node = new TreeNode(nums[mid]);
        new_node->left = insertInRange(nums, lower, mid-1);
        new_node->right = insertInRange(nums, mid+1, upper);
        return new_node;
    }
};