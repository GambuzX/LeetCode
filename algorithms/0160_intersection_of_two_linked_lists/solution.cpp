/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * inter = NULL;
        
        ListNode * iter = headA;
        while(iter != NULL) {
            iter->val *= -1;
            iter = iter->next;
        }
        
        iter = headB;
        while(iter != NULL) {
            if (iter->val < 0) {
                inter = iter;
                break;
            }
            iter = iter->next;
        }
        
        iter = headA;
        while(iter != NULL) {
            iter->val *= -1;
            iter = iter->next;
        }
        
        return inter;
    }
};