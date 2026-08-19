class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string &str : strs){
            s += to_string(str.length()) + ";" + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.length();){
            string len = "";
            while(s[i] != ';' && i < s.length()){
                len += s[i];
                i++;
            }
            i++;
            ans.push_back(s.substr(i, stoi(len)));
            i += stoi(len);
        }
        return ans;
    }
};
