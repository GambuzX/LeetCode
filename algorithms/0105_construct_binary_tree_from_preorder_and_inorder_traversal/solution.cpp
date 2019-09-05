/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.size() == 0) return NULL;
        
        unordered_map<int, int> inorder_indexes;
        for (int i = 0; i < inorder.size(); i++) inorder_indexes[inorder[i]] = i;
        
        int preIndex = 0;
        TreeNode * head = buildTree(preorder, inorder_indexes, 0, preorder.size()-1, preIndex);        
        return head;        
    }
    
    TreeNode * buildTree(vector<int>& preorder,unordered_map<int,int>& inorder_index, int start, int end, int & preIndex) {
        
        if (start > end) return NULL;
        
        TreeNode * newNode = new TreeNode(preorder[preIndex++]);
        
        if (start == end) return newNode;
        
        newNode->left = buildTree(preorder, inorder_index, start, inorder_index[newNode->val]-1, preIndex);
        newNode->right = buildTree(preorder, inorder_index, inorder_index[newNode->val]+1, end, preIndex);
        
        return newNode;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}