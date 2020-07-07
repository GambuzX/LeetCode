/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        iterativeDepthConnect(root);
        connect(root->left);
        connect(root->right);
        return root;
    }
    
    void iterativeDepthConnect(Node *root) {
        if (root == NULL || root->left == NULL || root->right == NULL) return;
        
        int depth = 1;
        while(true) {
            Node *left = root->left, *right = root->right;
            
            for (int i = 0; i < depth-1; i++) {
                
                int currDepth = i+2; 
                
                bool ll = left != NULL && hasPathWithDepth(left->left, currDepth, depth);
                bool lr = left != NULL && hasPathWithDepth(left->right, currDepth, depth);
                
                bool rl = right != NULL && hasPathWithDepth(right->left, currDepth, depth);
                bool rr = right != NULL && hasPathWithDepth(right->right, currDepth, depth);
                
                if (!ll && !lr) return;
                left = lr ? left->right: left->left;
                
                if (!rl && !rr) return;
                right = rl ? right->left : right->right;
            }
            
            left->next = right;
            
            depth++;
        }
    }
    
    bool hasPathWithDepth(Node *root, int currD, int targetD) {
        if (root == NULL) return false;
        
        if (currD >= targetD) return true;
        
        return hasPathWithDepth(root->left, currD+1, targetD) ||
                hasPathWithDepth(root->right, currD+1, targetD);
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
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
        TreeNode* root = stringToTreeNode(line);
        
        TreeNode* ret = Solution().connect(root);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}