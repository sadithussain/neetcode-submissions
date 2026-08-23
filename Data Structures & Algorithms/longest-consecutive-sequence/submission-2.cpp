class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int n : nums) {
            s.insert(n);
        }
        int max_len = 0;
        for(int n : nums) {
            if(!s.contains(n + 1)) {
                int len = 1;
                int num = n - 1;
                while(s.contains(num)) {
                    len++;
                    num--;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
