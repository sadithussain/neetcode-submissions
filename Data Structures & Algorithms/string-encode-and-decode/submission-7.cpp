class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string& str : strs) {
            ans += to_string(str.length()) + "." + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.length();) {
            string str_len;
            while(s[i] != '.') {
                str_len += s[i];
                i++;
            }
            int len = stoi(str_len);
            i++;
            ans.push_back(s.substr(i, len));
            i += len;
        }
        return ans;
    }
};
