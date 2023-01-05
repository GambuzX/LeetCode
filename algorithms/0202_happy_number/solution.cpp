class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.find(n) != seen.end()) return false;
            seen.insert(n);

            int sum = 0;
            while(n != 0) {
                int r = n % 10;
                n = n / 10;
                sum += pow(r, 2);
            }
            n = sum;
        }
        return true;
    }
};