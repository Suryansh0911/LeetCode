class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(k, INT_MAX);
        vector<int> sell(k+1, 0);

        for(auto price : prices){
            buy[0] = min(buy[0], price);
            for(int i=1; i<k; i++){
               sell[i-1] = max(sell[i-1], price-buy[i-1]);
               buy[i] = min(buy[i], price - sell[i-1]); 
            }
            sell[k] = max(sell[k], price - buy[k-1]);
        }
        return sell[k];
    }
};