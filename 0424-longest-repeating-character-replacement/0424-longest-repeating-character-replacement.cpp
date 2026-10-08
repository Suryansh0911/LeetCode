class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> frq(26, 0);
        int bestlen=INT_MIN;
        int left=0, ans=0;
        for(int right=0; right<n; right++){
            frq[s[right]-'A']++;
            int maxcount = max(maxcount, frq[s[right]-'A']);
            int len = right-left+1;
            int diff = len - maxcount;

            while(diff > k){
                frq[s[left]-'A']--;
                left++;
                len = right-left+1;
                diff = len - maxcount;
            }
            len = right - left + 1;
            ans = max(ans, len);
        }
        return ans;
    }
};