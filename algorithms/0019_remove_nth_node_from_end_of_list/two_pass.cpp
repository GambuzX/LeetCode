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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 0;
        ListNode * iter = head;
        while (iter != NULL) {
            size++;
            iter = iter->next;
        }
        
        if (n == size) return head->next;
        
        iter = head;
        for (int i = 0; i < size - n - 1; i++) {
            iter = iter->next;
        }
        
        if (n == 1) {
            iter->next = NULL;
        }
        else {
            iter->next = iter->next->next;
        }
        
        return head;
    }
};