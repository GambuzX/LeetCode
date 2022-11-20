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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        
        int size = 0;
        ListNode* last = nullptr;
        ListNode* iter = head;
        while (iter != nullptr) {
            if (iter->next == nullptr) last = iter;
            
            iter = iter->next;
            size++;
        }
        
        k = k%size;
        
        iter = head;
        for (int i = 0; i < size-k-1; i++) {
            iter = iter->next;
        }
        last->next = head;
        ListNode* newHead = iter->next;
        iter->next = nullptr;
        
        return newHead;
    }
};