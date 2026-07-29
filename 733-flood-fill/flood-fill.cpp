class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& Adj,int oldColor,int newColor){
    Adj[i][j] =newColor;// curr shell ko change to new color

    int n=Adj.size();
         int m=Adj[0].size();
    

    // up
    if(i-1>=0 &&  Adj[i-1][j]==oldColor){// vis contaon integer.
        dfs(i-1,j,Adj,oldColor,newColor);
    }
    // down
    if(i+1<n &&  Adj[i+1][j]==oldColor){
        dfs(i+1,j,Adj,oldColor,newColor);
    }
    // left
    if(j-1>=0 &&  Adj[i][j-1]==oldColor){
        dfs(i,j-1,Adj,oldColor,newColor);
    }
    // right
    if(j+1< m &&  Adj[i][j+1]==oldColor){
        dfs(i,j+1,Adj,oldColor,newColor);
    }
    

}
    vector<vector<int>> floodFill(vector<vector<int>>& Adj, int sr, int sc, int newColor) {
        int n=Adj.size();
         int m=Adj[0].size();

       
        int oldColor=Adj[sr][sc];//condtion 2
       if(oldColor==newColor) return Adj;// condtion 1

       dfs(sr,sc,Adj,oldColor,newColor);
       
        
       
        return Adj;
    }
};