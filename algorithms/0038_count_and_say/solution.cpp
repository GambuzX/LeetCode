class Solution {
public:
    string countAndSay(int n) {
        string base = "1";
        for (int i = 1; i < n; i++) {
            
            string newBase = "";
            int count = 1;
            char prev = base[0];
            for(int j = 1; j < base.length(); j++) {
                if (base[j] == prev) count++;
                else {
                    newBase += to_string(count) + prev;
                    count = 1;
                    prev = base[j];
                }
            }
            newBase += to_string(count) + prev;
            base = newBase;
        }
        return base;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}