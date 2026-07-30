// class Solution {
// public:

//     int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q,
//             vector<vector<int>>& dist) {

//         int n = grid.size();

//         while (!q.empty()) {

//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();

//             if (i == n - 1 && j == n - 1)
//                 return dist[i][j];

//             // Up
//             if (i - 1 >= 0 && grid[i - 1][j] == 0 && dist[i - 1][j] == 0) {
//                 dist[i - 1][j] = dist[i][j] + 1;
//                 q.push({i - 1, j});
//             }

//             // Down
//             if (i + 1 < n && grid[i + 1][j] == 0 && dist[i + 1][j] == 0) {
//                 dist[i + 1][j] = dist[i][j] + 1;
//                 q.push({i + 1, j});
//             }

//             // Left
//             if (j - 1 >= 0 && grid[i][j - 1] == 0 && dist[i][j - 1] == 0) {
//                 dist[i][j - 1] = dist[i][j] + 1;
//                 q.push({i, j - 1});
//             }

//             // Right
//             if (j + 1 < n && grid[i][j + 1] == 0 && dist[i][j + 1] == 0) {
//                 dist[i][j + 1] = dist[i][j] + 1;
//                 q.push({i, j + 1});
//             }

//             // Up-Left
//             if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 0 &&
//                 dist[i - 1][j - 1] == 0) {
//                 dist[i - 1][j - 1] = dist[i][j] + 1;
//                 q.push({i - 1, j - 1});
//             }

//             // Up-Right
//             if (i - 1 >= 0 && j + 1 < n && grid[i - 1][j + 1] == 0 &&
//                 dist[i - 1][j + 1] == 0) {
//                 dist[i - 1][j + 1] = dist[i][j] + 1;
//                 q.push({i - 1, j + 1});
//             }

//             // Down-Left
//             if (i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == 0 &&
//                 dist[i + 1][j - 1] == 0) {
//                 dist[i + 1][j - 1] = dist[i][j] + 1;
//                 q.push({i + 1, j - 1});
//             }

//             // Down-Right
//             if (i + 1 < n && j + 1 < n && grid[i + 1][j + 1] == 0 &&
//                 dist[i + 1][j + 1] == 0) {
//                 dist[i + 1][j + 1] = dist[i][j] + 1;
//                 q.push({i + 1, j + 1});
//             }
//         }

//         return -1;
//     }

//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

//         int n = grid.size();

//         if (grid[0][0] == 1 )
//             return -1;

//         queue<pair<int,int>> q;
//         vector<vector<int>> dist(n, vector<int>(n, 0));

//         q.push({0, 0});
//         dist[0][0] = 1;

//         return bfs(grid, q, dist);
//     }
// };

class Solution {
public:

    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q,
            vector<vector<int>>& vis) {

        int n = grid.size();
        int dist = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i == n - 1 && j == n - 1)
                    return dist;

                // Up
                if (i - 1 >= 0 && grid[i - 1][j] == 0 && vis[i - 1][j] == 0) {
                    vis[i - 1][j] = 1;
                    q.push({i - 1, j});
                }

                // Down
                if (i + 1 < n && grid[i + 1][j] == 0 && vis[i + 1][j] == 0) {
                    vis[i + 1][j] = 1;
                    q.push({i + 1, j});
                }

                // Left
                if (j - 1 >= 0 && grid[i][j - 1] == 0 && vis[i][j - 1] == 0) {
                    vis[i][j - 1] = 1;
                    q.push({i, j - 1});
                }

                // Right
                if (j + 1 < n && grid[i][j + 1] == 0 && vis[i][j + 1] == 0) {
                    vis[i][j + 1] = 1;
                    q.push({i, j + 1});
                }

                // Up-Left
                if (i - 1 >= 0 && j - 1 >= 0 &&
                    grid[i - 1][j - 1] == 0 && vis[i - 1][j - 1] == 0) {
                    vis[i - 1][j - 1] = 1;
                    q.push({i - 1, j - 1});
                }

                // Up-Right
                if (i - 1 >= 0 && j + 1 < n &&
                    grid[i - 1][j + 1] == 0 && vis[i - 1][j + 1] == 0) {
                    vis[i - 1][j + 1] = 1;
                    q.push({i - 1, j + 1});
                }

                // Down-Left
                if (i + 1 < n && j - 1 >= 0 &&
                    grid[i + 1][j - 1] == 0 && vis[i + 1][j - 1] == 0) {
                    vis[i + 1][j - 1] = 1;
                    q.push({i + 1, j - 1});
                }

                // Down-Right
                if (i + 1 < n && j + 1 < n &&
                    grid[i + 1][j + 1] == 0 && vis[i + 1][j + 1] == 0) {
                    vis[i + 1][j + 1] = 1;
                    q.push({i + 1, j + 1});
                }
            }

            dist++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        return bfs(grid, q, vis);
    }
};