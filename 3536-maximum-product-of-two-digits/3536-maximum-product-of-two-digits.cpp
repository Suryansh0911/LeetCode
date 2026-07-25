class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        int dig = 0;
        while(n>0){
            dig = n%10;
            n = n/10;
            digits.push_back(dig);
        }
        sort(digits.begin(), digits.end());
        return (digits[digits.size()-1]) * (digits[digits.size()-2]);
    }
};