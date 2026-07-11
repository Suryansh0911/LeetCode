class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> pSum(n + 1, 0); 
        vector<long long> pVal(n + 1, 0); 
        vector<int> pCnt(n + 1, 0);       
        
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            pSum[i + 1] = pSum[i] + digit;
            pCnt[i + 1] = pCnt[i] + (digit > 0 ? 1 : 0);
            
            if (digit > 0) {
                pVal[i + 1] = (pVal[i] * 10 + digit) % MOD;
            } else {
                pVal[i + 1] = pVal[i];
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = pSum[r + 1] - pSum[l];

            int nonZeros = pCnt[r + 1] - pCnt[l];

            long long leftVal = (pVal[l] * pow10[nonZeros]) % MOD;
            long long x = (pVal[r + 1] - leftVal + MOD) % MOD; 
            
            ans.push_back((int)((x * sum) % MOD));
        }
        
        return ans;
    }
};