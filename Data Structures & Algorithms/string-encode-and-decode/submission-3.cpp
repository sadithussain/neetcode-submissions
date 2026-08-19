class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string str : strs){
            s += to_string(str.length()) + "l" + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        for(int i = 0; i < s.size();){
            string len = "";
            while(s[i] != 'l'){
                len += s[i];
                i++;
            }
            i++;
            int n = stoi(len);
            v.push_back(s.substr(i, n));
            i += n;
        }
        return v;
    }
};
