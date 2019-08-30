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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * new_list = NULL;
        ListNode * iter;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                if (new_list == NULL) {
                    new_list = new ListNode(l2->val);
                    iter = new_list;
                }
                else {
                    iter->next = new ListNode(l2->val);
                    iter = iter->next;
                }
                l2 = l2->next;
            }
            else {
                if (new_list == NULL) {
                    new_list = new ListNode(l1->val);
                    iter = new_list;
                }
                else {
                    iter->next = new ListNode(l1->val);
                    iter = iter->next;
                }
                l1 = l1->next;
            }
        }
        
        while(l1 != NULL) {
            if (new_list == NULL) {
                new_list = new ListNode(l1->val);
                iter = new_list;
            }
            else {
                iter->next = new ListNode(l1->val);
                iter = iter->next;
            }
            l1 = l1->next;
        }
        while(l2 != NULL) {
            if (new_list == NULL) {
                new_list = new ListNode(l2->val);
                iter = new_list;
            }
            else {
                iter->next = new ListNode(l2->val);
                iter = iter->next;
            }
            l2 = l2->next;
        }        
        
        return new_list;
    }
};