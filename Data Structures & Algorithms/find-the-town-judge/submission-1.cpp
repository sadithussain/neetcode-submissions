class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n, 0);
        vector<int> trusted_by(n, 0);
        for(int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            v[a - 1]++;
            trusted_by[b - 1]++;
        }
        bool found = false;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(v[i] == 0) {
                // safety check if there are multiple people who
                // trust nobody
                // this means we don't have enough info
                if(found == true) {
                    return -1;
                }
                found = true;
                ans = i + 1;
            }
        }
        if(ans != -1 && trusted_by[ans - 1] == n - 1) {
            return ans;
        }
        return -1;
    }
};