class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(auto const &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            anagrams[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [key, group] : anagrams){
            ans.push_back(group);
        }
        return ans;
    }
};