class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string str : strs){
            s += to_string(str.size()) + "l" + str;
        }
        return s;
    }

    vector<string> decode(string s){
    vector<string> ans;

    for(int i = 0; i < s.size();){
        string str_len = "";
        while(s[i] != 'l'){
            str_len += s[i];
            i++;
        }
        int len = stoi(str_len);
        i++;
        string word = "";
        while(len > 0){
            word += s[i];
            i++;
            len--;
        }
        ans.push_back(word);
    }

    return ans;
}
};
