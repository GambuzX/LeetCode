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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode * newHead = head->next;
        
        ListNode * i1 = head;
        ListNode * i2 = head->next;
        
        while(i1 != NULL && i2 != NULL) {
            ListNode * temp = i2->next;
            i2->next = i1;
            if (temp != NULL && temp->next != NULL)
                i1->next = temp->next;
            else
                i1->next = temp;
            
            i1 = temp;
            if (i1 != NULL) i2 = i1->next;
        }
        
        return newHead;
    }
};