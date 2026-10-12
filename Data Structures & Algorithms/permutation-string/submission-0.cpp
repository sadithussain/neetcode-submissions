class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) {
            return false;
        }
        vector<int> s1_freq(26, 0);
        for(char c : s1) {
            s1_freq[c - 'a']++;
        }
        vector<int> s2_freq(26, 0);
        for(int i = 0; i < s1.length() - 1; i++) {
            char c = s2[i];
            s2_freq[c - 'a']++;
        }
        int n = s1.length();
        int right = n - 1;
        while(right < s2.length()) {
            char c = s2[right];
            s2_freq[c - 'a']++;
            if(s1_freq == s2_freq) { 
                return true;
            }
            right++;
            s2_freq[s2[right - n] - 'a']--;
        }
        return false;
    }
};
