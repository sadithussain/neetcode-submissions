class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int k = 0;
        int i = 0;
        while(i < nums.size()) {
            if(!s.contains(nums[i])) {
                s.insert(nums[i]);
                swap(nums[i], nums[k]);
                k++;
            }
            i++;
        }
        return k;
    }
};