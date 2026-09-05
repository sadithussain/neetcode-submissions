class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int left_bound = st.empty() ? -1 : st.top();
                int width = i - left_bound - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        int right_bound = heights.size() - 1;
        while(!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int left_bound = st.empty() ? -1 : st.top();
            int width = right_bound - left_bound;
            max_area = max(max_area, height * width);
        }
        return max_area;
    }
};
