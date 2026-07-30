class Solution {
public:
int bfs(vector<vector<int>>& Adj,queue<pair<int,int>>& q,vector<vector<int>> & dist){
    
    int n=Adj.size();
        int m=Adj[0].size();

        while(!q.empty()){
            int size=q.size();

            for(int k=0;k<size;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                // up
                if(i-1>=0 && dist[i-1][j]==-1){
                    dist[i-1][j]=dist[i][j]+1;
                    q.push({i-1,j});
                }
                if(i+1<n && dist[i+1][j]==-1){
                    dist[i+1][j]=dist[i][j]+1;
                    q.push({i+1,j});
                }
                if(j-1>=0 && dist[i][j-1]==-1){
                    dist[i][j-1]=dist[i][j]+1;
                    q.push({i,j-1});
                }
                if(j+1<m && dist[i][j+1]==-1){
                    dist[i][j+1]=dist[i][j]+1;
                    q.push({i,j+1});
                }
            }
        }
        int mx=dist[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx=max(mx,dist[i][j]);
            }
        }
        return mx;

}
    int maxDistance(vector<vector<int>>& Adj) {
         int n=Adj.size();
        int m=Adj[0].size();

        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        int land=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Adj[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;// pahele assign zero at 0,0 in dist mat
                    land++;
                }
            }
        }
        if(land==0 || land==n*m){// what describe -> all water or all land
            return -1;
        }
        return bfs(Adj,q,dist);
    }
};