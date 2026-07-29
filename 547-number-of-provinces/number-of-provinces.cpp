class Solution {
public:

// void dfs(int start,vector<vector<int>>& Adj,vector<int>& vis){
//     vis[start]=1;
//     for(int i=0;i<Adj[start].size();i++){// or vis.size()
//         if(vis[i]==0 && Adj[start][i]==1){
//             dfs(i,Adj,vis);
//         }
//     }
// }
//     int findCircleNum(vector<vector<int>>& Adj) {
//         int n=Adj.size();
//         int cnt=0;
//         vector<int> vis(n,0);
//         for(int i=0;i<n;i++){
//             if(vis[i]==0){
//                 cnt++;
//                 dfs(i,Adj,vis);
//             }
//         }
//         return cnt;
//     }
// };

// void dfs(int start,vector<vector<int>>& Adj,vector<int>& vis){
//    stack<int> st;
//    st.push(start);
//    while(!st.empty()){
//     int x =st.top();
//     st.pop();
//     vis[x]=1;

//     for(int i=0;i<vis.size();i++){
//         if(Adj[x][i]==1 && vis[i]==0){
//             st.push(i);
//         }
//     }
//    }
// }
//     int findCircleNum(vector<vector<int>>& Adj) {
//         int n=Adj.size();
//         int cnt=0;
//         vector<int> vis(n,0);
//         for(int i=0;i<n;i++){
//             if(vis[i]==0){
//                 cnt++;
//                 dfs(i,Adj,vis);
//             }
//         }
//         return cnt;
//     }
// };

// void bfs(int start,vector<vector<int>>& Adj,vector<int>& vis){
//    queue<int> q;
//    q.push(start);
//    while(!q.empty()){
//     int x=q.front();
    
//     vis[x]=1;

//     for(int i=0;i<vis.size();i++){
//         if(Adj[x][i]==1 && vis[i]==0){
//             q.push(i);
//         }
//     }
//     q.pop();
//    }
// }
//     int findCircleNum(vector<vector<int>>& Adj) {
//         int n=Adj.size();
//         int cnt=0;
//         vector<int> vis(n,0);
//         for(int i=0;i<n;i++){
//             if(vis[i]==0){
//                 cnt++;
//                 bfs(i,Adj,vis);
//             }
//         }
//         return cnt;
//     }
// };

    void dfs(int start,vector<vector<int>>& Adj,vector<int> & vis){
        vis[start]=1;

        for(int i=0;i<Adj[0].size();i++){
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