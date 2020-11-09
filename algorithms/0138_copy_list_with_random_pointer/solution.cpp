/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (head == NULL) return NULL;
        
        Node* iter = head;
        unordered_map<Node*,int> random_index;
        
        int index = 0;
        vector<Node*> nodes;
        while(iter != NULL) {
            nodes.push_back(new Node(iter->val));
            random_index[iter] = index++;
            iter = iter->next;
        }
        
        int i = 0;
        iter = head;
        while(iter != NULL) {
            nodes[i]->next = (i < nodes.size()-1 ? nodes[i+1] : NULL);
            nodes[i]->random = (iter->random == NULL ? NULL : nodes[random_index[iter->random]]);
            iter = iter->next;
            i++;
        }
        return nodes[0];
    }
};