class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(k, INT_MAX);
        vector<int> sell(k, 0);
        for(int price : prices){
            buy[0] = min(buy[0], price);
            sell[0] = max(sell[0], price-buy[0]);

            for(int i=1; i<k; i++){
                buy[i] = min(buy[i], price - sell[i-1]);
                sell[i] = max(sell[i], price-buy[i]);
            }
        }
        return sell[k-1];
    }
};