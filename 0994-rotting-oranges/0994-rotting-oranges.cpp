class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> qu;

        // Push all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    qu.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;

        while (!qu.empty()) {

            int row = qu.front().first.first;
            int col = qu.front().first.second;
            int time = qu.front().second;

            qu.pop();

            ans = max(ans, time);

            // Top
            if (row - 1 >= 0 &&
                !vis[row - 1][col] &&
                grid[row - 1][col] == 1) {

                vis[row - 1][col] = true;
                qu.push({{row - 1, col}, time + 1});
            }

            // Bottom
            if (row + 1 < n &&
                !vis[row + 1][col] &&
                grid[row + 1][col] == 1) {

                vis[row + 1][col] = true;
                qu.push({{row + 1, col}, time + 1});
            }

            // Left
            if (col - 1 >= 0 &&
                !vis[row][col - 1] &&
                grid[row][col - 1] == 1) {

                vis[row][col - 1] = true;
                qu.push({{row, col - 1}, time + 1});
            }

            // Right
            if (col + 1 < m &&
                !vis[row][col + 1] &&
                grid[row][col + 1] == 1) {

                vis[row][col + 1] = true;
                qu.push({{row, col + 1}, time + 1});
            }
        }

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};