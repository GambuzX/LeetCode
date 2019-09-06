/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        queue<Node*> to_visit;
        to_visit.push(node);
        
        unordered_set<int> visited;
        visited.insert(node->val);
        
        unordered_map<int, Node*> copied_nodes;
        
        while(!to_visit.empty()) {
            Node * next_node = to_visit.front();
            to_visit.pop();
            
            // if not copied yet, copy it            
            if(!copied_nodes.count(next_node->val)) copied_nodes[next_node->val] = new Node(next_node->val, {});
            
            for (Node* & iter : next_node->neighbors) {
                
                // BFS
                if (visited.find(iter->val) == visited.end()) {
                    to_visit.push(iter);
                    visited.insert(iter->val);
                }
                
                if(!copied_nodes.count(iter->val)) copied_nodes[iter->val] = new Node(iter->val, {});
                
                copied_nodes[next_node->val]->neighbors.push_back(copied_nodes[iter->val]);
            }
        }
        
        return copied_nodes[node->val];
    }
};