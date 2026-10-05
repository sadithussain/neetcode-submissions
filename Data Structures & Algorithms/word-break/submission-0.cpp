class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            if(!dp[i]) {
                continue;
            }
            for(string& str : wordDict) {
                string next = s.substr(0, i) + str;
                int len = next.length();
                if(len > n) {
                    continue;
                }
                if(s.substr(0, len) == next) {
                    dp[len] = true;
                }
            }
        }
        return dp[n];
    }
};
