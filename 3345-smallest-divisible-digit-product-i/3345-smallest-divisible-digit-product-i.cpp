class Solution {
public:
    int prod(int n){
        int pro = 1, digit=0;
        while(n>0){
            digit = n%10;
            pro *= digit;
            n = n/10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        for(int i=n; i<n+10; i++){
            if(prod(i) % t == 0) return i;
        }
        return 0;
    }
};