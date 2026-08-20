class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26);
        for(int i = 0; i < order.size(); i++) {
            v[order[i] - 'a'] = i;
        }
        int max_len = 0;
        for(string& word : words) {
            max_len = std::max(max_len, (int)word.length());
        }
        vector<long long> words_values;
        for(int i = 0; i < words.size(); i++) {
            long long value = 0;
            string& word = words[i];
            int exp = max_len - 1;
            for(int j = 0; j < word.length(); j++)  {
                value += v[word[j] - 'a'] * pow(26, exp);
                exp--;
            }
            words_values.push_back(value);
        }
        long long max_value = words_values[0];
        for(int i = 1; i < words_values.size(); i++) {
            if(words_values[i] < max_value) {
                return false;
            }
            max_value = words_values[i];
        }
        return true;
    }
};