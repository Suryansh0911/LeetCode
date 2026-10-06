class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(t.empty() || m < n) return "";
        vector<int> frq(256, 0);
        for(char ch : t) frq[ch]++;
        int left=0, required=n, start=0, len=INT_MAX;
        for(int right=0; right<m; right++){
            if(frq[s[right]] > 0) required--;
            frq[s[right]]--;
            while(required == 0){
                if(right-left+1 < len){
                    len = right-left+1;
                    start = left;
                }
                frq[s[left]]++;
                if(frq[s[left]] > 0) required++;
                left++;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};