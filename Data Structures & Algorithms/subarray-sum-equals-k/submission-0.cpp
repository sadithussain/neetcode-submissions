class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int n : nums) {
            sum += n;
            int target = sum - k;
            ans += m[target];
            m[sum]++;
        }
        return ans;
    }
};