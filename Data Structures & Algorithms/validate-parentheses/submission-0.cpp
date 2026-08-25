class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string open = "({[";
        string close = ")}]";
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(open.contains(c)) {
                st.push(c);
            }
            else {
                if(st.empty()) {
                    return false;
                }
                if(c == close[0]) {
                    if(st.top() != open[0]) {
                        return false;
                    }
                }
                else if(c == close[1]) {
                    if(st.top() != open[1]) {
                        return false;
                    }
                }
                else {
                    if(st.top() != open[2]) {
                        return false;
                    }
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
