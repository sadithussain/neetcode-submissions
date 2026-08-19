class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string& str : strs) {
            vector<int> v(26, 0);
            for(char& c : str) {
                v[c - 'a']++;
            }
            string key;
            for(int n : v) {
                key += to_string(n) + ".";
            }
            m[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = m.begin(); it != m.end(); it++) {
            ans.push_back(it -> second);
        }
        return ans;
    }
};
