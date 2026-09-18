class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for(const auto &s : strs){
            vector<int> freq(26, 0);
            for(char ch : s){
                freq[ch-'a']++;
            }
            string key;
            for(int count : freq){
                key += to_string(count);
                key += '#';
            }
            map[key].push_back(s);
        }
        for(const auto& [key, group] : map){
            ans.push_back(group);
        }
        return ans;
    }
};