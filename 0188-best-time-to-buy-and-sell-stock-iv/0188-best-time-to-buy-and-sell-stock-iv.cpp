class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int actions = 2 * k;

        vector<int> next(actions + 1, 0);
        vector<int> curr(actions + 1, 0);

        for(int i = prices.size() - 1; i >= 0; i--) {

            for(int action = 1; action <= actions; action++) {

                if(action % 2 == 0)
                    curr[action] = max(-prices[i] + next[action - 1],
                                       next[action]);
                else
                    curr[action] = max(prices[i] + next[action - 1],
                                       next[action]);
            }

            next = curr;
        }

        return next[actions];
    }
};