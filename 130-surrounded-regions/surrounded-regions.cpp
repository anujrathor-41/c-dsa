class Solution {
public:

    void bfs(vector<vector<char>>& Adj,vector<vector<int>> &vis,queue<pair<int,int>> &q){
        int n=Adj.size();
        int m=Adj[0].size();

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();
            
            // up
            if(i-1>=0 && vis[i-1][j]==0 && Adj[i-1][j]=='O'){
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            // down
            if(i+1<n && vis[i+1][j]==0 && Adj[i+1][j]=='O'){
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
            // left
            if(j-1>=0 && vis[i][j-1]==0 && Adj[i][j-1]=='O'){
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
            // right
            if(j+1<m && vis[i][j+1]==0 && Adj[i][j+1]=='O'){
                vis[i][j+1]=1;
                q.push({i,j+1});
            }

        }
    }
    

    void solve(vector<vector<char>>& Adj) {
        int n=Adj.size();
        int m=Adj[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        // first row
        for(int j=0;j<m;j++){
           if(Adj[0][j]=='O'  && vis[0][j]==0){
            vis[0][j]=1;
            q.push({0,j});
            bfs(Adj,vis,q);
           }
        }
        // last row
        for(int j=0;j<m;j++){
           if(Adj[n-1][j]=='O'  && vis[n-1][j]==0){
            vis[n-1][j]=1;
            q.push({n-1,j});
            bfs(Adj,vis,q);
           }
        }
        // first col
        for(int i=0;i<n;i++){
            if(Adj[i][0]=='O' && vis[i][0]==0){
                vis[i][0]=1;
                q.push({i,0});
                bfs(Adj,vis,q);
            }
        }
        // last col
        for(int i=0;i<n;i++){
            if(Adj[i][m-1]=='O' && vis[i][m-1]==0){
                vis[i][m-1]=1;
                q.push({i,m-1});
                bfs(Adj,vis,q);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Adj[i][j]=='O' && vis[i][j]==0){
                    Adj[i][j]='X';

                }
            }
        }
       
    }
};