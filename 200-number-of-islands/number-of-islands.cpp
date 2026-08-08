class Solution {
public:
int vis[301][301];
    void bfs(vector<vector<char>>& Adj,queue<pair<int,int>>& q) {

        int n = Adj.size();
        int m = Adj[0].size();

        while (!q.empty()) {

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Up
            if (i - 1 >= 0 && vis[i - 1][j] == 0 && Adj[i - 1][j] == '1') {
                vis[i - 1][j] = 1;
                q.push({i - 1, j});
            }

            // Down
            if (i + 1 < n && vis[i + 1][j] == 0 && Adj[i + 1][j] == '1') {
                vis[i + 1][j] = 1;
                q.push({i + 1, j});
            }

            // Left
            if (j - 1 >= 0 && vis[i][j - 1] == 0 && Adj[i][j - 1] == '1') {
                vis[i][j - 1] = 1;
                q.push({i, j - 1});
            }

            // Right
            if (j + 1 < m && vis[i][j + 1] == 0 && Adj[i][j + 1] == '1') {
                vis[i][j + 1] = 1;
                q.push({i, j + 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& Adj) {

        int n = Adj.size();
        int m = Adj[0].size();

        // vector<vector<int>> vis(n, vector<int>(m, 0));
        memset(vis,0,sizeof(vis));

        int cnt = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vis[i][j] == 0 && Adj[i][j] == '1') {

                    
                    q.push({i, j});
                    vis[i][j] = 1;

                    bfs(Adj, q);

                    cnt++;
                }
            }
        }

        return cnt;
    }
};