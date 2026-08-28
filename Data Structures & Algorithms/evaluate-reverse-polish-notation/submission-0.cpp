class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string& token : tokens) {
            if(token == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 + num2);
            }
            else if(token == "-") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            }
            else if(token == "*") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 * num2);
            }
            else if(token == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
