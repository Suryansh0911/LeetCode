class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occur(26, 0);
        for(int i=0; i<s.size(); i++){
            last_occur[s[i] - 'a'] = i;
        }
        vector<bool> visited(26, false);
        string result="";

        for(int i=0; i<s.size(); i++){
            char curr_char = s[i];
            int curr_idx = s[i] - 'a';
            if(visited[curr_idx]){
                continue;
            }
            while(!result.empty() && result.back() > curr_char && last_occur[result.back() - 'a'] > i){
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(curr_char);
            visited[curr_idx] = true;
        }
        return result;
    }
};