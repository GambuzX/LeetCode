class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        int l = n.length();
        
        vector<pair<int,int>> right_max(l);
        right_max[l-1] = make_pair(n[l-1]-'0',l-1);
        for (int i = l-2; i >= 0; i--) {
            int curr = n[i]-'0';
            int next = right_max[i+1].first;
            right_max[i] = curr > next ? make_pair(curr, i) : make_pair(next, right_max[i+1].second);
        }
        
        int i = 0;
        while(i < l && right_max[i].first == n[i]-'0') i++;
        
        if (i >= l) return num;
        
        string cpy = n;
        cpy[i] = n[right_max[i].second];
        cpy[right_max[i].second] = n[i];
        
        return stoi(cpy);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        int ret = Solution().maximumSwap(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}