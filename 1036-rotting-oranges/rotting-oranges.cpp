class Solution {
public:

    int bfsLevel(vector<vector<int>>& Adj,
                 queue<pair<int,int>>& q,
                 vector<vector<int>>& vis,
                 int freshCnt) {

        int n = Adj.size();
        int m = Adj[0].size();

        int time = 0;

        while (!q.empty() && freshCnt > 0) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // Up
                if (i - 1 >= 0 && Adj[i - 1][j] == 1 && vis[i - 1][j] == 0) {
                    vis[i - 1][j] = 1;
                    freshCnt--;
                    q.push({i - 1, j});
                }

                // Down
                if (i + 1 < n && Adj[i + 1][j] == 1 && vis[i + 1][j] == 0) {
                    vis[i + 1][j] = 1;
                    freshCnt--;
                    q.push({i + 1, j});
                }

                // Left
                if (j - 1 >= 0 && Adj[i][j - 1] == 1 && vis[i][j - 1] == 0) {
                    vis[i][j - 1] = 1;
                    freshCnt--;
                    q.push({i, j - 1});
                }

                // Right
                if (j + 1 < m && Adj[i][j + 1] == 1 && vis[i][j + 1] == 0) {
                    vis[i][j + 1] = 1;
                    freshCnt--;
                    q.push({i, j + 1});
                }
            }

            time++;
        }

        if (freshCnt > 0)
            return -1;

        return time;
    }

    int orangesRotting(vector<vector<int>>& Adj) {

        int n = Adj.size();
        int m = Adj[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int freshCnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (Adj[i][j] == 2) {
                   
                    vis[i][j] = 1;
                     q.push({i, j});
                }

                if (Adj[i][j] == 1) {
                    freshCnt++;
                }
            }
        }

        return bfsLevel(Adj, q, vis, freshCnt);
    }
};
