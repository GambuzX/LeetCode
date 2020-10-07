class Solution {
public:
    int fib(int N) {
        int i1 = 0, i2 = 1;
        for (int i = 2; i <= N; i++) {
            int newI = i1 + i2;
            i1 = i2;
            i2 = newI;
        }
        return N == 0 ? 0 : i2;
    }
};