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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(-1);
        ListNode * curr = result;
        
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            else carry = 0;
            
            if (curr->val == -1) {
                curr->val = sum;
            }
            else {
                curr->next = new ListNode(sum);
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL) {
            int sum = l1->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            else carry = 0;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int sum = l2->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            else carry = 0;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l2 = l2->next;
        }
        
        if(carry) {
            curr->next = new ListNode(1);
        }
        
        return result;
    }
};