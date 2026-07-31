class Solution {
public:

    void bfs(vector<vector<char>>& board,
             vector<vector<int>>& vis,
             queue<pair<int,int>>& q){

        int n = board.size();
        int m = board[0].size();

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Up
            if(i-1 >= 0 && board[i-1][j] == 'O' && vis[i-1][j] == 0){
                vis[i-1][j] = 1;
                q.push({i-1,j});
            }

            // Down
            if(i+1 < n && board[i+1][j] == 'O' && vis[i+1][j] == 0){
                vis[i+1][j] = 1;
                q.push({i+1,j});
            }

            // Left
            if(j-1 >= 0 && board[i][j-1] == 'O' && vis[i][j-1] == 0){
                vis[i][j-1] = 1;
                q.push({i,j-1});
            }

            // Right
            if(j+1 < m && board[i][j+1] == 'O' && vis[i][j+1] == 0){
                vis[i][j+1] = 1;
                q.push({i,j+1});
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;

        // First Row
        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                vis[0][j]=1;
                q.push({0,j});
                bfs(board,vis,q);
            }
        }

        // Last Row
        for(int j=0; j<m; j++){
            if(board[n-1][j]=='O' && vis[n-1][j]==0){
                vis[n-1][j]=1;
                q.push({n-1,j});
                bfs(board,vis,q);
            }
        }

        // First Column
        for(int i=0; i<n; i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                vis[i][0]=1;
                q.push({i,0});
                bfs(board,vis,q);
            }
        }

        // Last Column
        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                vis[i][m-1]=1;
                q.push({i,m-1});
                bfs(board,vis,q);
            }
        }

        // Convert surrounded O to X
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }

            }
        }
    }
};