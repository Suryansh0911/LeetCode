class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left=0, best=0;
        for(int right=0; right<s.length(); right++){
            char c = s[right];
            if(map.count(c) && map[c] >= left){
                left = map[c] + 1;
            }
            map[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};