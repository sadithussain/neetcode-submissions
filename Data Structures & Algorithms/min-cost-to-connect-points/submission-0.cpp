class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = calculate_distance(points[i], points[j]);
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<bool> visited(n, false);
        int ans = 0;
        min_heap.push({0, 0});
        while(!min_heap.empty()) {
            auto [cost, point] = min_heap.top();
            min_heap.pop();
            if(visited[point]) {
                continue;
            }
            ans += cost;
            visited[point] = true;
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    min_heap.push({adj[point][i], i});
                }
            }
        }
        return ans;
    }
    int calculate_distance(vector<int>& a, vector<int>& b) {
        return static_cast<int>(abs(a[0] - b[0]) + abs(a[1] - b[1]));
    }
};