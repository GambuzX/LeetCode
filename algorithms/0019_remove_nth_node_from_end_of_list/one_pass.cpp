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
        
        ListNode * i1 = head, * i2 = head;
        
        for (int i = 0 ; i < n; i++) i2 = i2->next;
        
        // n = list size
        if (i2 == NULL) return head->next;
        
        while(i2->next != NULL) {
            i1 = i1->next;
            i2 = i2->next;
        }
        
        i1->next = i1->next->next;
        
        return head;
    }
};