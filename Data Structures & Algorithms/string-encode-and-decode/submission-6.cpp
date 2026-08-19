class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs) {
            ans += to_string(s.length()) + "." + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.length();) {
            int len = s[i] - '0';
            i++;
            while(s[i] != '.') {
                len = len * 10 + s[i] - '0';
                i++;
            }
            i++;
            ans.push_back(s.substr(i, len));
            i += len;
        }
        return ans;
    }
};
