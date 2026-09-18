class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for(const auto &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        for(const auto [key, group] : map){
            ans.push_back(group);
        }
        return ans;
    }
};