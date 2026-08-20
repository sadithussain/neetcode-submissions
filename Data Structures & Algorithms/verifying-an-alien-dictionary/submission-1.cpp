class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26);
        for(int i = 0; i < order.size(); i++) {
            v[order[i] - 'a'] = i;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            string& word1 = words[i];
            string& word2 = words[i + 1];
            bool sorted = false;
            for(int j = 0; j < min(word1.length(), word2.length()); j++) {
                int letter1 = v[word1[j] - 'a'];
                int letter2 = v[word2[j] - 'a'];
                if(letter1 < letter2) {
                    sorted = true;
                    break;
                }
                else if(letter2 < letter1) {
                    return false;
                }
            }
            if(!sorted && word2.length() < word1.length()) {
                return false;
            }
        }
        return true;
    }
};