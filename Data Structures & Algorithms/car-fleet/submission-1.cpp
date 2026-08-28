class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> st;
        vector<pair<int, int>> cars(n);
        for(int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());
        st.push(calculate_time(target - cars[n - 1].first, cars[n - 1].second));
        for(int i = n - 2; i >= 0; i--) {
            double time = calculate_time(target - cars[i].first, cars[i].second);
            if(time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
    double calculate_time(int distance, int speed) {
        return static_cast<double>(distance) / speed;
    }
};
