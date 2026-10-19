class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n && i < k; i++) {
            if(!m.contains(nums[i])) {
                m[nums[i]] = i;
            }
            else {
                return true;
            }
        }
        for(int i = k; i < n; i++) {
            if(!m.contains(nums[i])) {
                m[nums[i]] = i;
            }
            else {
                return true;
            }
            m.erase(nums[i - k]);
        }
        return false;
    }
};