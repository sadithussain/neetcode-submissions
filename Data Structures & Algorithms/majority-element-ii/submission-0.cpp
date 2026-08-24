class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0;
        int b = 1;
        int count_a = 0;
        int count_b = 0;
        for(int n : nums) {
            if(n == a) {
                count_a++;
            }
            else if(n == b) {
                count_b++;
            }
            else if(count_a == 0) {
                a = n;
                count_a = 1;
            }
            else if(count_b == 0) {
                b = n;
                count_b = 1;
            }
            else {
                count_a--;
                count_b--;
            }
        }
        count_a = 0;
        count_b = 0;
        for(int n : nums) {
            if(a == n) {
                count_a++;
            }
            else if(b == n) {
                count_b++;
            }
        }
        vector<int> ans;
        int n = nums.size();
        if(count_a > n / 3) {
            ans.push_back(a);
        }
        if(count_b > n / 3) {
            ans.push_back(b);
        }
        return ans;
    }
};