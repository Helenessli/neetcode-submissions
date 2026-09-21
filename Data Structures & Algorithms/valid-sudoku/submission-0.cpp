class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];

                if (num == '.') {
                    continue;
                }

                // Find which 3x3 box this cell belongs to
                int box = (r / 3) * 3 + (c / 3);

                // Check if number already exists
                if (rows[r].count(num) ||
                    cols[c].count(num) ||
                    boxes[box].count(num)) {
                    return false;
                }

                // Add number to the corresponding sets
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};