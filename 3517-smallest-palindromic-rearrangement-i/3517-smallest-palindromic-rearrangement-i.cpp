class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1) return s;
        int freq[26]{};
        int n = s.size(); int j=0;
        for(int i=0; i<n>>1; i++){
            freq[(s[i] & 31) - 1]++;
        }

        for(int i=0; i<26; i++){
            while(freq[i]--){
                s[j] = 'a' + i;
                s[n-1-j++] = 'a' + i;
            }
        }
        return s;
    }
};