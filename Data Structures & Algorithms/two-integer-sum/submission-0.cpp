class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = m.find(complement);
            if(it != m.end()) {
                return {it -> second, i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
