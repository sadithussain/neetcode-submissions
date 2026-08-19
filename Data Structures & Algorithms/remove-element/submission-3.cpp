class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while(right >= 0 && nums[right] == val) {
            right--;
        }
        while(left < right) {
            if(nums[left] == val) {
                swap(nums[left], nums[right]);
                right--;
                while(right >= left && nums[right] == val) {
                    right--;
                }
            }
            left++;
        }
        return right + 1;
    }
};