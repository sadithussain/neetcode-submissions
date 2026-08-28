class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 1;
        while(i < path.size() && path[i] == '/') {
            i++;
        }
        while(i < path.size()) {
            size_t pos = path.find('/', i + 1);
            int index = (pos == string::npos) ? path.size() : static_cast<int>(pos);
            string directory = path.substr(i, index - i);
            if(directory == ".") {
                
            }
            else if(directory == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(directory);
            }
            i = index;
            while(i < path.size() && path[i] == '/') {
                i++;
            }
        }
        string ans;
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};