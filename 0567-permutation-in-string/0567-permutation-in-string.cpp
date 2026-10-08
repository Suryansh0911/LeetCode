class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        vector<int> frq1(26, 0), frq2(26, 0);
        for(char ch : s1){
            frq1[ch-'a']++;
        }
        for(int i=0; i<s1.length(); i++){
            frq2[s2[i]-'a']++;
        }
        if(frq1 == frq2) return true;
        for(int i=s1.length(); i<s2.length(); i++){
            frq2[s2[i]-'a']++;
            frq2[s2[i-s1.length()]-'a']--;
            if(frq1 == frq2) return true;
        }
        return false;
    }
};