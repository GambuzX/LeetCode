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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* iter = head;
        while(iter != nullptr) {
            ListNode* curr = iter;
            iter = iter->next;
            while(iter != nullptr && iter->val == curr->val) {
                iter = iter->next;
            }
            curr->next = iter;
        }
        return head;
    }
};