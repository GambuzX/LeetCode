class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x == 0) return x;
        
        int l = 1, r = x;
        int mid;
        long long pow1, pow2;
        while(l < r) {
            mid = l + (r-l)/2;
            pow1 = (long long) mid*mid;
            pow2 = (long long) (mid+1)*(mid+1);
            
            if (pow1 == x) return mid;
            else if (pow1 < x && x < pow2) return mid;
            else {
                pow1 > x ? (r = mid) : (l = mid+1);
            }
        }
        return mid;        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}