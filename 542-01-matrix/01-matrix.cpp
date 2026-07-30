// class Solution {
// public:

// vector<vector<int>> bfs(vector<vector<int>>& Adj,queue<pair<int,int>>& q,vector<vector<int>> & dist){
//     int n=Adj.size();
//         int m=Adj[0].size();

//         while(!q.empty()){
//             int size=q.size();

//             for(int k=0;k<size;k++){
//                 int i=q.front().first;
//                 int j=q.front().second;
//                 q.pop();

//                 // up
//                 if(i-1>=0 && dist[i-1][j]==-1){
//                     dist[i-1][j]=dist[i][j]+1;
//                     q.push({i-1,j});
//                 }
//                 if(i+1<n && dist[i+1][j]==-1){
//                     dist[i+1][j]=dist[i][j]+1;
//                     q.push({i+1,j});
//                 }
//                 if(j-1>=0 && dist[i][j-1]==-1){
//                     dist[i][j-1]=dist[i][j]+1;
//                     q.push({i,j-1});
//                 }
//                 if(j+1<m && dist[i][j+1]==-1){
//                     dist[i][j+1]=dist[i][j]+1;
//                     q.push({i,j+1});
//                 }
//             }
//         }
//         return dist;

// }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& Adj) {

//         int n=Adj.size();
//         int m=Adj[0].size();

//         vector<vector<int>> dist(n,vector<int>(m,-1));
//         queue<pair<int,int>> q;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(Adj[i][j]==0){
//                     q.push({i,j});
//                     dist[i][j]=0;// pahele assign zero at 0,0 in dist mat
//                 }
//             }
//         }
//         return bfs(Adj,q,dist);
//     }
// };
class Solution {
public:

    vector<vector<int>> bfs(vector<vector<int>>& mat,
                            queue<pair<int,int>>& q,
                            vector<vector<int>>& ans,
                            vector<vector<int>>& vis) {

        int n = mat.size();
        int m = mat[0].size();

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                ans[i][j] = level;

                // Up
                if (i - 1 >= 0 && vis[i - 1][j] == 0) {
                    vis[i - 1][j] = 1;
                    q.push({i - 1, j});
                }

                // Down
                if (i + 1 < n && vis[i + 1][j] == 0) {
                    vis[i + 1][j] = 1;
                    q.push({i + 1, j});
                }

                // Left
                if (j - 1 >= 0 && vis[i][j - 1] == 0) {
                    vis[i][j - 1] = 1;
                    q.push({i, j - 1});
                }

                // Right
                if (j + 1 < m && vis[i][j + 1] == 0) {
                    vis[i][j + 1] = 1;
                    q.push({i, j + 1});
                }
            }

            level++;
        }

        return ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // Push all 0's into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        return bfs(mat, q, ans, vis);
    }
};