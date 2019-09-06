class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<char>> edgesMatrix(numCourses, vector<char>(numCourses, 0));
        unordered_set<int> candidates;
        vector<vector<int>> destinations(numCourses, vector<int>());
        
        for (auto & ele : prerequisites) {
            edgesMatrix[ele[0]][ele[1]] = 1;
            
            if (candidates.find(ele[1]) != candidates.end()) {
                candidates.erase(ele[1]);
            }
            candidates.insert(ele[0]);
            
            destinations[ele[0]].push_back(ele[1]);
        }
        
        return !hasLoop(edgesMatrix, candidates, destinations);
    }
    
    bool hasLoop(vector<vector<char>>& edgesMatrix, const unordered_set<int>& candidates, const vector<vector<int>> & destinations) {
        
        for (auto & elem : candidates) {
            if (!dfs(edgesMatrix, elem, destinations)) return true;
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& edgesMatrix, int root, const vector<vector<int>> & destinations) {
        bool no_loop = true;
        
        for (int dest : destinations[root]) {
            char res = edgesMatrix[root][dest];
            
            // loop
            if (res == -1) return false;
            
            if (res == 1) {
                edgesMatrix[root][dest] = -1;
                
                no_loop &= dfs(edgesMatrix, dest, destinations);
                
                edgesMatrix[root][dest] = 1;
            }
                
            if(!no_loop) return false;
        }
        
        return no_loop;
    }
};