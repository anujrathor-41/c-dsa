class Solution {
public:

void dfs(int i,int j,vector<vector<char>>& Adj,vector<vector<int>>& vis){
    vis[i][j] =1;

    int n=Adj.size();
         int m=Adj[0].size();
    

    // up
    if(i-1>=0 && vis[i-1][j]==0 && Adj[i-1][j]=='1'){// vis contaon integer.
        dfs(i-1,j,Adj,vis);
    }
    // down
    if(i+1<n && vis[i+1][j]==0 && Adj[i+1][j]=='1'){
        dfs(i+1,j,Adj,vis);
    }
    // left
    if(j-1>=0 && vis[i][j-1]==0 && Adj[i][j-1]=='1'){
        dfs(i,j-1,Adj,vis);
    }
    // right
    if(j+1< m && vis[i][j+1]==0 && Adj[i][j+1]=='1'){
        dfs(i,j+1,Adj,vis);
    }

}
    int numIslands(vector<vector<char>>& Adj) {
         int n=Adj.size();
         int m=Adj[0].size();

        int cnt=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(vis[i][j] == 0 && Adj[i][j] =='1'){
                cnt++;
                dfs(i,j,Adj,vis);
            }

            }
           
        }
        return cnt;
    }
};