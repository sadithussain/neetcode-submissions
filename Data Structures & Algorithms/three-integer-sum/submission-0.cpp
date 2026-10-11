class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 1;) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum <= 0) {
                    if(sum == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                    j++;
                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
                else {
                    k--;
                    while(j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
            i++;
            while(i < nums.size() - 1 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return ans;
    }
};
