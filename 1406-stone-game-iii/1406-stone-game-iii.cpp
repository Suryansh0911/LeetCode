class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int best = INT_MIN;
            int run_sum = 0;
            for(int k=1; k<4; k++){
                if(i+k > n){
                    break;
                }
                run_sum += stoneValue[i+k-1];
                best = max(best, run_sum - dp[i+k]);
            }
            dp[i] = best;
        }
        if(dp[0] > 0){
            return "Alice";
        }else if(dp[0] < 0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};