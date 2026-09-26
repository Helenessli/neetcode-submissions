class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Put every treasure into the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // Check 4 directions
            vector<pair<int, int>> directions = {
                {1, 0},
                {-1, 0},
                {0, 1},
                {0, -1}
            };

            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                // Out of bounds
                if (newRow < 0 || newCol < 0 ||
                    newRow >= rows || newCol >= cols) {
                    continue;
                }

                // Only process untouched land
                if (grid[newRow][newCol] != INT_MAX) {
                    continue;
                }

                grid[newRow][newCol] = grid[row][col] + 1;

                q.push({newRow, newCol});
            }
        }
    }
};