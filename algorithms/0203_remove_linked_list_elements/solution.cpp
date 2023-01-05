/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) return head;

        ListNode* prev = head;
        ListNode* iter = head->next;
        while(iter != nullptr) {
            if (iter->val == val) {
                iter = iter->next;
                prev->next = iter;
            }
            else {
                prev = iter;
                iter = iter->next;
            }
        }

        return head;
    }
};