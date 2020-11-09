struct Node {
    int val;
    vector<Node*> children;
    Node(int i) {
        val = i;
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<Node> nodes;
        for(int i = 0; i < graph.size(); i++)
            nodes.push_back(Node(i));
        for(int i = 0; i < graph.size(); i++)
            for(int j = 0; j < graph[i].size(); j++)
                nodes[i].children.push_back(&nodes[graph[i][j]]);
        
        vector<vector<int>> res;
        getAllPaths(&nodes[0], nodes.size()-1, {}, res);        
        return res;
    }
    
    void getAllPaths(Node *src, int dst, vector<int> pathSoFar, vector<vector<int>> &res) {
        pathSoFar.push_back(src->val);
        if (src->val == dst) {
            res.push_back(pathSoFar);
            return;
        }
        
        for(Node* child : src->children)
            getAllPaths(child, dst, pathSoFar, res);        
    }
};