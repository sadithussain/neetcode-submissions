class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            if(left < right && tolower(s[left]) != tolower(s[right])) {
                if(isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
    bool isPalindrome(string s, int left, int right) {
        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            if(left < right && tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};