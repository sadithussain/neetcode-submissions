class Solution {
private:
    int calculate_perimeter(vector<vector<int>>& grid, int row, int col) {
        set<pair<int, int>> visited;
        stack<pair<int, int>> st;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        st.push({row, col});
        visited.insert({row, col});
        while(!st.empty()) {
            auto [r, c] = st.top();
            st.pop();
            for(vector<int>& v : dir) {
                int dr = v[0];
                int dc = v[1];
                int new_row = r + dr;
                int new_col = c + dc;
                if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || grid[new_row][new_col] == 0) {
                    perimeter++;
                }
                else {
                    if(!visited.contains({new_row, new_col})) {
                        st.push({new_row, new_col});
                        visited.insert({new_row, new_col});
                    }
                }
            }
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == 1) {
                    return calculate_perimeter(grid, row, col);
                }
            }
        }
        return 0;
    }
};