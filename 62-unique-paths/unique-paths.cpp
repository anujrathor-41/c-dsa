// class Solution {
// public:
// int t[101][101];
// int solve(int m,int n,int i,int j){
//     if(i==m || j==n) return 0;
//    if(i==m-1 && j==n-1) return 1;
//      if(t[i][j]!=-1) return t[i][j];

//         return t[i][j]= solve(m,n,i+1,j) + solve(m,n,i,j+1);
// }
//     int uniquePaths(int m, int n) {
//         memset(t,-1,sizeof(t));
//         return solve(m,n,0,0);
        
//     }
// };

class Solution {
public:

int solve(int m,int n,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=solve(m,n,i+1,j,dp) + solve(m,n,i,j+1,dp);
}

    int uniquePaths(int m, int n) {//without using memset or sir ka tarika
       vector<vector<int>> dp(m,vector<int> (n,-1));// placing -1 in grid
        for(int i=0;i<m;i++){
            dp[i][n-1] =1;
        }
        for(int j=0;j<n;j++){
            dp[m-1][j]=1;
        }
        return solve(m,n,0,0,dp);
        
    }
};