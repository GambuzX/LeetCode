class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!dividend) return 0;
        if(divisor == 1) return dividend;
        long num1 = dividend;
        long num2 = divisor;
        int sign = 1;
        long xorbits = -1;
        // get result sign and convert to positive
        if(dividend < 0)
        {
            sign *= -1;
            num1 = (dividend^xorbits)+1;
        }
        if(divisor < 0)
        {
            sign *= -1;
            num2 = (divisor^xorbits)+1;
        }
        if(num1 < num2) return 0;
        // run division
        long q = 0;
        long r = 0;
        long d;
        int k = significantBit((void*)&num1, sizeof(long));
        int l = significantBit((void*)&num2, sizeof(long));
		// compute r
        for(int i = 0; i <= l-2; i++)
        {
            int alpha = (num1 >> (k-i-1)) & 0b1;
            r += (1 << (l-2-i)) * alpha;
        }
		// compute q and r
        for(int i = 0; i <= k-l; i++)
        {
            int alpha = (num1 >> (k-i-l)) & 0b1;
            d = (r << 1) + alpha;
            int beta = !(d < num2);
            r = d - num2 * beta;
            q = (q << 1) + beta;
        }
        q *= sign;
		// if overflow, return 2^31-1
        if(q < -0x7FFFFFFF-1 || q > 0x7FFFFFFF) return 0x7FFFFFFF;
        return (int)q;
    }
    
    int significantBit(void* ptr, size_t size)
    {
		// access data byte by byte
        unsigned char* b = (unsigned char*)ptr;
        int count = 0;
        for(int i = size-1; i >= 0; i--)
        {
            for(int j = 7; j >= 0; j--)
            {
                if(b[i] >> j & 0b1)
                    return (size*8-count);
                count++;
            }
        }
        return (size*8-count);
    }
};