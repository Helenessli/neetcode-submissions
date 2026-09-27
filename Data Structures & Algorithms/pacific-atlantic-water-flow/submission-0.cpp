class Solution {
public:
    int rows, cols;

    void bfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             queue<pair<int, int>>& q) {

        int directions[4][2] = {
            {-1, 0},  // up
            {1, 0},   // down
            {0, -1},  // left
            {0, 1}    // right
        };

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Check bounds
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                    continue;
                }

                // Already visited
                if (visited[nr][nc]) {
                    continue;
                }

                // Reverse flow:
                // neighbor must be >= current cell
                if (heights[nr][nc] < heights[r][c]) {
                    continue;
                }

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // Pacific: top row
        for (int c = 0; c < cols; c++) {
            pacific[0][c] = true;
            pacificQueue.push({0, c});
        }

        // Pacific: left column
        for (int r = 0; r < rows; r++) {
            if (!pacific[r][0]) {
                pacific[r][0] = true;
                pacificQueue.push({r, 0});
            }
        }

        // Atlantic: bottom row
        for (int c = 0; c < cols; c++) {
            atlantic[rows - 1][c] = true;
            atlanticQueue.push({rows - 1, c});
        }

        // Atlantic: right column
        for (int r = 0; r < rows; r++) {
            if (!atlantic[r][cols - 1]) {
                atlantic[r][cols - 1] = true;
                atlanticQueue.push({r, cols - 1});
            }
        }

        // Find cells that can reach Pacific
        bfs(heights, pacific, pacificQueue);

        // Find cells that can reach Atlantic
        bfs(heights, atlantic, atlanticQueue);

        // Cells that can reach both
        vector<vector<int>> result;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};