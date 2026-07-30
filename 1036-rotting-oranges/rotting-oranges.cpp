// class Solution {
// public:

//     int bfs(vector<vector<int>>& grid,
//             queue<pair<int,int>>& q,
//             int fresh) {

//         int n = grid.size();
//         int m = grid[0].size();
//         int time = 0;

//         while(!q.empty() && fresh > 0) {

//             int size = q.size();

//             for(int k = 0; k < size; k++) {

//                 int i = q.front().first;
//                 int j = q.front().second;
//                 q.pop();

//                 // Down
//                 if(i + 1 < n && grid[i + 1][j] == 1) {
//                     grid[i + 1][j] = 2;
//                     fresh--;
//                     q.push({i + 1, j});
//                 }

//                 // Up
//                 if(i - 1 >= 0 && grid[i - 1][j] == 1) {
//                     grid[i - 1][j] = 2;
//                     fresh--;
//                     q.push({i - 1, j});
//                 }

//                 // Right
//                 if(j + 1 < m && grid[i][j + 1] == 1) {
//                     grid[i][j + 1] = 2;
//                     fresh--;
//                     q.push({i, j + 1});
//                 }

//                 // Left
//                 if(j - 1 >= 0 && grid[i][j - 1] == 1) {
//                     grid[i][j - 1] = 2;
//                     fresh--;
//                     q.push({i, j - 1});
//                 }
//             }

//             time++;
//         }

//         if(fresh > 0)
//             return -1;

//         return time;
//     }


//     int orangesRotting(vector<vector<int>>& grid) {

//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<int,int>> q;
//         int fresh = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {

//                 if(grid[i][j] == 2) {
//                     q.push({i, j});
//                 }

//                 if(grid[i][j] == 1) {
//                     fresh++;
//                 }
//             }
//         }

//         return bfs(grid, q, fresh);
//     }
// };

class Solution {
public:

    int bfsLevel(vector<vector<int>>& Adj,queue<pair<int,int>> q,int freshCnt){
        int n=Adj.size();
        int m=Adj[0].size();

        int time=0;
        //up down left right when Adj[i][j]==1 and rott the shell and dec freshcnt and call bfs means push in queue
        while(!q.empty() && freshCnt>0){
            int size=q.size();
            for(int k=0;k<size;k++){
                int i=q.front().first;// pair ka first
                int j=q.front().second;// pair ka secod
                q.pop();

                // up
                if(i-1>=0 && Adj[i-1][j]==1){
                    Adj[i-1][j]=2;
                    freshCnt--;
                    q.push({i-1,j});
                }
                // down
                if(i+1<n && Adj[i+1][j]==1){
                    Adj[i+1][j]=2;
                    freshCnt--;
                    q.push({i+1,j});
                }
                if(j-1>=0 && Adj[i][j-1]==1){
                    Adj[i][j-1]=2;
                    freshCnt--;
                    q.push({i,j-1});
                }
                if(j+1<m && Adj[i][j+1]==1){
                    Adj[i][j+1]=2;
                    freshCnt--;
                    q.push({i,j+1});
                }

            }
            time++;
        }
        if(freshCnt>0) return -1;
        return time;
        

    }


    int orangesRotting(vector<vector<int>>& Adj) {

        int n=Adj.size();
        int m=Adj[0].size();

        int freshCnt=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Adj[i][j]==2){
                    q.push({i,j});
                }
                if(Adj[i][j]==1){
                    freshCnt++;
                }
            }
        }
        return bfsLevel(Adj,q,freshCnt);// while + size +for
    }
};