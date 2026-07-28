class Solution {
public:

void dfs(int start,vector<vector<int>>& Adj,vector<int>& vis){
    vis[start]=1;
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0 && Adj[start][i]==1){
            dfs(i,Adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& Adj) {
        int n=Adj.size();
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,Adj,vis);
            }
        }
        return cnt;
    }
};