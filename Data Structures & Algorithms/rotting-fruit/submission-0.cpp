class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    fresh++;
                }
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int min = 0;
        while (fresh){
            if (q.empty()){
                return -1;
            }
            vector<pair<int,int>> directions = {
                {1, 0}, {0, 1}, {-1, 0}, {0, -1}
            };
            int qSize = q.size();
            for (int i = 0; i < qSize; i++){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for (auto [x, y] : directions){
                    int newRow = row + x;
                    int newCol = col + y;
                    if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() || grid[newRow][newCol] != 1){
                        continue;
                    }
                    fresh--;
                    grid[newRow][newCol] = 2;
                    q.push({newRow, newCol});
                }
            }
            min++;
        }
        
        return min;
    }
};
/*
rotten fruit are bfs sources. put them all into the queue.
while there are still fresh fruit remaining, bfs.
if the queue becomes empty but fresh fruit remain, return -1.
keep track of the minutes.
modify fresh to rotton fruit in place.
*/