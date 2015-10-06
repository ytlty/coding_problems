/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

const int MAX_INT = 2147483647;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 1;
        int quotient = 0;
        long abs_dividend = dividend;
        long abs_divisor = divisor;
        int mask = dividend >> 31;
        abs_dividend ^= mask;
        abs_dividend -= mask;
        
        mask = divisor >> 31;
        abs_divisor ^= mask;
        abs_divisor -= mask;
        
        std::cout << abs_dividend << std::endl;
        std::cout << abs_divisor << std::endl;
        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0)){
            result = -1;
        }
        if (abs_dividend < abs_divisor) {
            return 0;
        }
        if (divisor == 0) {
            return MAX_INT;
        }
        if (dividend == 0) {
            return 0;
        }
        if (abs_divisor == 1) {
            if (divisor < 0 && dividend < 0) { 
                if (abs_dividend > MAX_INT) {
                    return MAX_INT;
                }
                return abs_dividend;
            } else if (dividend < 0 && divisor > 0){
                return dividend;
            } else if (dividend > 0 && divisor < 0){
                return -dividend;
            }
            if (abs_dividend > MAX_INT) {
                return MAX_INT;
            }
            return abs_dividend;
        }
        if (abs_dividend == abs_divisor) {
            return (result == -1)? -1 : 1;
        }
        int step = 1;
        long divisor_copy = abs_divisor;
        
        while(divisor_copy < abs_dividend)
    	{
    	    divisor_copy = divisor_copy << 1; // Logical bit-shift left.
    	    step = step << 1; // Logical bit-shift left.
    	}
    	
    	while (divisor_copy >= abs_divisor)
    	{
    	    while(abs_dividend >= divisor_copy)
    	    {
    	        abs_dividend -= divisor_copy;
    	        quotient += step;
    	    }
    	    step=step>>1;
    	    divisor_copy=divisor_copy>>1;
    	}
        if (result == -1) {
            return -quotient;
        }
        return quotient;
    }
};
