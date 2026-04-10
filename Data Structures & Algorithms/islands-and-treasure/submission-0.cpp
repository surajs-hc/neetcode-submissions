class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        const int dRow[] = {0, 0, -1, 1};
        const int dCol[] = {-1, 1, 0, 0};

        int height = grid.size();
        int width = grid[0].size();
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            const auto [row, col] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int newRow = row + dRow[d];
                int newCol = col + dCol[d];

                if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && grid[newRow][newCol] == INT_MAX) {
                    grid[newRow][newCol] = grid[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};
