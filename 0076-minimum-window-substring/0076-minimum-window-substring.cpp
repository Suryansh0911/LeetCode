class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        unordered_map<char, int> need, have;
        for(char c : t) need[c]++;
        int required = need.size();
        int formed = 0;

        int left=0, bestlen=INT_MAX, beststart=0;

        for(int right=0; right<s.size(); right++){
            char c = s[right];
            have[c]++;
            if(need.count(c) && need[c]==have[c]){
                formed++;
            }

            while(formed == required){
                if(right-left+1 < bestlen){
                    bestlen = right-left+1;
                    beststart = left;
                }
                char l = s[left];
                have[l]--;
                if(need.count(l) && have[l] < need[l]) formed--;
                left++;
            }
        }
        return bestlen == INT_MAX ? "" : s.substr(beststart, bestlen);
    }
};