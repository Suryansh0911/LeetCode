class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        return n + max(n-8, 0) + max(n-16, 0) + max(n-24, 0);
    }
};