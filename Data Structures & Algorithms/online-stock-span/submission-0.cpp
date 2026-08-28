class StockSpanner {
private:
    stack<int> st;
    stack<int> span;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!st.empty() && st.top() <= price) {
            ans += span.top();
            st.pop();
            span.pop();
        }
        st.push(price);
        span.push(ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */