class Solution {
private:
    int memo[201][201][201];
    const int MOD = 1e9 + 7;

    int solve(int i, int gcd1, int gcd2, const std::vector<int>& nums) {

        if (i == nums.size()) {
            return (gcd1 > 0 && gcd1 == gcd2) ? 1 : 0;
        }

        if (memo[i][gcd1][gcd2] != -1) {
            return memo[i][gcd1][gcd2];
        }

        long long ans = solve(i + 1, gcd1, gcd2, nums);

        int next_gcd1 = (gcd1 == 0) ? nums[i] : std::gcd(gcd1, nums[i]);
        ans = (ans + solve(i + 1, next_gcd1, gcd2, nums)) % MOD;

        int next_gcd2 = (gcd2 == 0) ? nums[i] : std::gcd(gcd2, nums[i]);
        ans = (ans + solve(i + 1, gcd1, next_gcd2, nums)) % MOD;

        return memo[i][gcd1][gcd2] = ans;
    }

public:
    int subsequencePairCount(std::vector<int>& nums) {
        std::memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};