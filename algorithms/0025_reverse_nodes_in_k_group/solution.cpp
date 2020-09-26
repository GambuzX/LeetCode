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
    
    void printList(ListNode *head) {
        ListNode *iter = head;
        while(iter != nullptr) {
            cout << iter->val << " ";
            iter = iter->next;
        }
        cout << endl;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        
        ListNode* newHead = nullptr;
        ListNode* prevHead = nullptr;
        ListNode* iter = head;
        stack<ListNode*> s;
        
        while(iter != nullptr) {
            // put up to k elements in stack
            for(int i = 0; i < k; i++) {
                if(iter == nullptr) return newHead;
                s.push(iter);
                iter = iter->next;
            }

            // reverse k elements
            ListNode* prev = s.top(); s.pop();
            
            if (newHead == nullptr)
                newHead = prev;
            else
                prevHead->next = prev;
            
            while(!s.empty()) {
                ListNode* curr = s.top(); s.pop();
                prev->next = curr;
                prev = curr;            
            }
            prev->next = iter;
            prevHead = prev;
        }      
        
        return newHead;
    }
};