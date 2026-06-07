class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;

        int fresh = 0;

        // Store all rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }

                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans = 0;

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();

            ans = max(ans, time);

            // Top
            if(row - 1 >= 0 && grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                fresh--;
                q.push({{row - 1, col}, time + 1});
            }

            // Bottom
            if(row + 1 < n && grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                fresh--;
                q.push({{row + 1, col}, time + 1});
            }

            // Left
            if(col - 1 >= 0 && grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                fresh--;
                q.push({{row, col - 1}, time + 1});
            }

            // Right
            if(col + 1 < m && grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                fresh--;
                q.push({{row, col + 1}, time + 1});
            }
        }

        if(fresh > 0)
            return -1;

        return ans;
    }
};