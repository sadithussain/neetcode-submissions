class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int n : asteroids) {
            bool exploded = false;
            bool this_positive = n > 0;

            while(!st.empty()) {
                int other = st.top();
                bool positive = other > 0;
                
                if(positive && !this_positive) {
                    int sum = n + other;
                    if(sum < 0) {
                        st.pop();
                    }
                    else {
                        exploded = true;
                        if(sum == 0) {
                            st.pop();
                        }
                        break;
                    }
                }
                else {
                    break;
                }
            }

            if(!exploded) {
                st.push(n);
            }
        }
        vector<int> ans(st.size());
        for(int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};