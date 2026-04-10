class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int, int>> points;
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int k = 0; k < grid[i].size(); ++k) {
                // bfs
                if (grid[i][k] == 1) {
                    points.push({i, k});
                    grid[i][k] = 0;

                    int area = 0;
                    while (!points.empty()) {
                        const auto [row, col] = points.top();
                        points.pop();
                        ++area;

                        int dRow[] = {0, 0, -1, 1};
                        int dCol[] = {-1, 1, 0, 0};
                        for (int d = 0; d < 4; ++d) {
                            int newRow = row + dRow[d];
                            int newCol = col + dCol[d];
                            if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[i].size() || grid[newRow][newCol] == 0) {
                                continue;
                            }
                            points.push({newRow, newCol});
                            grid[newRow][newCol] = 0;
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
