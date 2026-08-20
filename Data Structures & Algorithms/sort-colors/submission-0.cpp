class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);
        for(int n : nums) {
            colors[n]++;
        }
        int i = 0;
        while(i < colors[0]) {
            nums[i] = 0;
            i++;
        }
        while(i < colors[0] + colors[1]) {
            nums[i] = 1;
            i++;
        }
        while(i < colors[0] + colors[1] + colors[2]) {
            nums[i] = 2;
            i++;
        }
    }
};