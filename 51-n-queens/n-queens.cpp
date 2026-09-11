class Solution {
public:

    bool check(int row,int col,vector<string> &temp,int n){
        // 3 bc
        // up
        int r=row-1;
        while(r>=0){
            if(temp[r--][col]=='Q'){
                return false;
            }
        }
        r=row-1;
        int c=col-1;
        while(r>=0 && c>=0){
            if(temp[r--][c--]=='Q'){
                return false;
            }
        }
        r=row-1;
        c=col+1;
        while(r>=0 && c<n){
            if(temp[r--][c++]=='Q'){
                return false;
            }
        }
        return true;

    }
    void solve(vector<vector<string>> &ans,vector<string> &temp,int n,int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(check(row,col,temp,n)){
                temp[row][col]='Q';
                solve(ans,temp,n,row+1);
                // bt
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        solve(ans,temp,n,0);
        return ans;
    }
};