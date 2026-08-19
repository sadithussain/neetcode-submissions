class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(string s : strs){
            str += to_string(s.length()) + "." + s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.length();){
            string len = "";
            while(s[i] != '.'){
                len += s[i];
                i++;
            }
            i++;
            int n = stoi(len);
            ans.push_back(s.substr(i, n));
            i += n;
        }
        return ans;
    }
};
