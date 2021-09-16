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
    TreeNode* findMaxDepth(TreeNode* head, int depth, unordered_map<TreeNode*,int> &nodesMaxDepth) {
        if (head == nullptr) return nullptr;
        
        nodesMaxDepth[head] = depth;
        
        TreeNode* left = findMaxDepth(head->left, depth+1, nodesMaxDepth);
        TreeNode* right = findMaxDepth(head->right, depth+1, nodesMaxDepth);
        if (left == nullptr) left = head;
        if (right == nullptr) right = head;
        
        int leftMaxDepth = nodesMaxDepth[left];
        int rightMaxDepth = nodesMaxDepth[right];
        nodesMaxDepth[head] = max(leftMaxDepth, rightMaxDepth);
        
        if (leftMaxDepth == rightMaxDepth) return head;
        else if (leftMaxDepth > rightMaxDepth) return left;
        else return right;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*,int> nodesMaxDepth;
        return findMaxDepth(root, 0, nodesMaxDepth);
    }
};