class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // Out of bounds or water
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() ||
            grid[r][c] == '0') {
            return;
        }

        // Mark this land as visited
        grid[r][c] = '0';

        // Visit up, down, left, right
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {

                if (grid[r][c] == '1') {
                    islands++;

                    // Explore the entire island
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};