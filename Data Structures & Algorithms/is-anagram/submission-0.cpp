class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_freq(26, 0);
        for(char& c : s) {
            s_freq[c - 'a']++;
        }
        vector<int> t_freq(26, 0);
        for(char& c : t) {
            t_freq[c - 'a']++;
        }
        return s_freq == t_freq;
    }
};
