class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1 ; i < strs.size(); i++) {
            int cutoff = 0;
            string& str = strs[i];
            int n = min(str.length(), ans.length());
            while(cutoff < n && ans[cutoff] == str[cutoff]) {
                cutoff++;
            }
            if(cutoff < n) {
                ans.resize(cutoff);
            }
        }
        return ans;
    }
};