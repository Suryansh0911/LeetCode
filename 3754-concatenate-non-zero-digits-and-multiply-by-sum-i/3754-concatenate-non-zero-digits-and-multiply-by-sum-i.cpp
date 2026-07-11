class Solution {
public:
    long long sumAndMultiply(int n) {
        int multiplier = 1;
        long long x = 0;
        int sum = 0;
        while(n != 0){
            int digit = n % 10;
            n = n / 10;
            if(digit != 0){
                x += digit * multiplier;
                multiplier *= 10;
                sum += digit;
            } 
        }
        return (long long)sum * x;
    }
};