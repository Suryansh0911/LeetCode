class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> map;
        int i=0, j=0, count=0;
        while(j < s.size()){
            map[s[j]]++;
            while(map[s[j]] > 2){
                map[s[i]]--;
                i++;
            }
            count = max(count, j-i+1);
            j++;
        }
        return count;

    }
};