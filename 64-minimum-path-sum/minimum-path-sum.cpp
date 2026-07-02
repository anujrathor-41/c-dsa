class Solution {
public:
int t[201][201] ;
int solve(vector<vector<int>> &grid ,int m,int n,int i,int j )
{
    if(i==m || j==n) return INT_MAX ;// boundary se bahar na jaye
    if(i==m-1 && j==n-1) return grid[i][j] ;
    if(t[i][j] !=-1) return t[i][j];

    return t[i][j]= grid[i][j] + min(solve(grid,m,n,i+1,j) , solve(grid,m,n,i,j+1));
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid,m,n,0,0);

        
    }
};