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
    ListNode* reverseList(ListNode* head) {
        
        ListNode * prev = NULL;
        
        ListNode * iter = head;
        
        while(iter != NULL) {
            ListNode * nextNode = iter->next;            
            iter->next = prev;
            prev = iter;
            iter = nextNode;
        }
        
        return prev;
    }
};