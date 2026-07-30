// class Solution {
// public:
//     void dfs(int i,int j,vector<vector<int>>& Adj,vector<vector<int>>& vis){
//     vis[i][j] =1;

//     int n=Adj.size();
//          int m=Adj[0].size();
    
//     int area=1;

//     // up
//     if(i-1>=0 && vis[i-1][j]==0 && Adj[i-1][j]==1){// vis contaon integer.
//         area +=dfs(i-1,j,Adj,vis);
//     }
//     // down
//     if(i+1<n && vis[i+1][j]==0 && Adj[i+1][j]==1){
//         area +=dfs(i+1,j,Adj,vis);
//     }
//     // left
//     if(j-1>=0 && vis[i][j-1]==0 && Adj[i][j-1]==1){
//         area +=dfs(i,j-1,Adj,vis);
//     }
//     // right
//     if(j+1< m && vis[i][j+1]==0 && Adj[i][j+1]==1){
//         area +=dfs(i,j+1,Adj,vis);
//     }

// }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int n=Adj.size();
//          int m=Adj[0].size();

//         int cnt=0;
        
//         vector<vector<int>> vis(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                  if(vis[i][j] == 0 && Adj[i][j] ==1){
              
//                     int area=dfs(i,j,Adj,vis);
//                     mx=max(mx,area);
//                     }

//             }
           
//         }
//         return area;
//     }
// };

class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int& area) {

        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        // count current land cell
        area++;

        // up
        if(i - 1 >= 0 && vis[i-1][j] == 0 && grid[i-1][j] == 1) {
            dfs(i-1, j, grid, vis, area);
        }

        // down
        if(i + 1 < n && vis[i+1][j] == 0 && grid[i+1][j] == 1) {
            dfs(i+1, j, grid, vis, area);
        }

        // left
        if(j - 1 >= 0 && vis[i][j-1] == 0 && grid[i][j-1] == 1) {
            dfs(i, j-1, grid, vis, area);
        }

        // right
        if(j + 1 < m && vis[i][j+1] == 0 && grid[i][j+1] == 1) {
            dfs(i, j+1, grid, vis, area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && vis[i][j] == 0) {

                    // new island, so start area from 0
                    int area = 0;

                    dfs(i, j, grid, vis, area);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};