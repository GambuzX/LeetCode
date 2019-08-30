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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        if (p != NULL) s1.push(p);
        if (q != NULL) s2.push(q);
        
        while(!s1.empty() && !s2.empty()) {
            TreeNode* t1 = s1.top();
            TreeNode* t2 = s2.top();
            
            s1.pop();
            s2.pop();
            
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            
            if (t1->val != t2->val) return false;
            
            s1.push(t1->right);
            s1.push(t1->left);
            
            s2.push(t2->right); 
            s2.push(t2->left);    
            
        }
        
        return s1.empty() && s2.empty();
    }
};