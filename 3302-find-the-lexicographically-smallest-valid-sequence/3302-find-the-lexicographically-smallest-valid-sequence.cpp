class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int r = n-1;
        int c = 0;

        vector<int> right(m);
        for(int i=m-1; i>=0; i--){
            right[i] = c;
            if(r>=0 && word1[i] == word2[r]){
                r--; c++;
            }
        }

        vector<int> ans;
        bool changed = false;
        int j=0;

        for(int i=0; i<m && j<n; i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }else if(!changed && right[i] >= n-1-j){
                ans.push_back(i); j++;
                changed = true;
            }
        }

        if(j==n) return ans;
        return {};
    }
};