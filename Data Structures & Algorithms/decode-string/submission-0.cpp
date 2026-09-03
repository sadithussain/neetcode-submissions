class Solution {
public:
    string decodeString(string s) {
        string str;
        int count = 0;
        int i = 0;
        stack<pair<int, string>> st;
        while(i < s.length()) {
            char& c = s[i];
            if(isdigit(c)) {
                count = count * 10 + (c - '0');
            }
            else if(isalpha(c)) {
                str += c;
            }
            else if(c == '[') {
                st.push({count, str});
                count = 0;
                str = "";
            }
            else {
                string temp_str;
                auto [old_count, old_str] = st.top();
                st.pop();
                for(int j = 0; j < old_count; j++) {
                    temp_str += str;
                }
                str = old_str + temp_str;
                count = 0;
            }
            i++;
        }
        return str;
    }
};