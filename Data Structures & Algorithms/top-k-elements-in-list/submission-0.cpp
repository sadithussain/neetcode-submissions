class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int n : nums) {
            m[n]++;
        }
        priority_queue<pair<int, int>> max_heap;
        for(auto it = m.begin(); it != m.end(); it++) {
            max_heap.push({it -> second, it -> first});
        }
        vector<int> ans;
        while(ans.size() < k) {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
};
