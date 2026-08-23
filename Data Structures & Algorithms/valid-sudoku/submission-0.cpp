class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> boxes(9);
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                char& c = board[row][col];
                if(c == '.') {
                    continue;
                }
                if(rows[row].contains(c)) {
                    return false;
                }
                rows[row].insert(c);
                if(cols[col].contains(c)) {
                    return false;
                }
                cols[col].insert(c);
                int box = (row / 3) * 3 + col / 3;
                if(boxes[box].contains(c)) {
                    return false;
                }
                boxes[box].insert(c);
            }
        }
        return true;
    }
};
