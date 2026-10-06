class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(t.empty() || m < n) return "";
        vector<int> frq(256, 0);
        for(char ch : t) frq[ch]++;
        int low=0, required=n, ans=INT_MAX, start=0;
        for(int high=0; high<m; high++){
            if(frq[s[high]] > 0) required--;
            frq[s[high]]--;
            while(required == 0){
                if(high-low+1 < ans){
                    ans = high-low+1;
                    start = low;
                }
                frq[s[low]]++;
                if(frq[s[low]] > 0) required++;
                low++;
            }
        }
        return (ans == INT_MAX) ? "" : s.substr(start, ans);
    }
};