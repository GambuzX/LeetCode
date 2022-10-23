class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t newn = 0;        
        for (int i = 0; i < 32; i++) {
            newn <<= 1;
            newn += n & 1;
            n >>= 1;
        }        
        return newn;
    }
};