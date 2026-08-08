class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,queue<pair<int,int>> &q  ,
             int& area) {

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
           
            
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                area++;

                // up
                if (i - 1 >= 0 && vis[i - 1][j] == 0 && grid[i - 1][j] == 1) {
                    q.push({i-1,j});
                    vis[i-1][j]=1;
                }

                // down
                if (i + 1 < n && vis[i + 1][j] == 0 && grid[i + 1][j] == 1) {
                     q.push({i+1,j});
                    vis[i+1][j]=1;
                }

                // left
                if (j - 1 >= 0 && vis[i][j - 1] == 0 && grid[i][j - 1] == 1) {
                     q.push({i,j-1});
                    vis[i][j-1]=1;
                }

                // right
                if (j + 1 < m && vis[i][j + 1] == 0 && grid[i][j + 1] == 1) {
                    q.push({i,j+1});
                    vis[i][j+1]=1;
                }
            
        }

        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && vis[i][j] == 0) {

                    // new island, so start area from 0
                    int area = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                    bfs(grid, vis,q, area);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};