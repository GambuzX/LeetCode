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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * newList = NULL;
        
        for (ListNode* & list : lists) {
            newList = mergeLists(newList, list);
        }
        
        return newList;
    }
    
    ListNode* mergeLists(ListNode* i1, ListNode* i2) {
        if (i1 == NULL) return i2;
        if (i2 == NULL) return i1;
        
        ListNode * newHead = new ListNode(0);
        ListNode * iter = newHead;
        
        while(i1 != NULL && i2 != NULL) {
            if (i1->val < i2->val) {
                iter->next = i1;
                iter = iter->next;
                i1 = i1->next;
                
            }
            else {
                iter->next = i2;
                iter = iter->next;
                i2 = i2->next;
            }
        }
        
        if (i1 == NULL) iter->next = i2;
        if (i2 == NULL) iter->next = i1;
        
        return newHead->next;
    }
};