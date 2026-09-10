class Solution {
public:
    int t[100001][2][3];
    int mod=1e9+7;
    int solve(int i,int n,int absent,int late){
        if(i==n) return 1;

        if(t[i][absent][late]!=-1) return t[i][absent][late];

        // present ki choice hamesa hai
        int ans=solve(i+1,n,absent,0);

        // absent ki choice
        if(absent<1){
           ans += solve(i+1,n,absent+1,0);
           ans %=mod;
        }
        // late ki choice kab hai
        if(late<2){
          ans +=  solve(i+1,n,absent,late+1);
          ans %= mod;
        }
        return t[i][absent][late]= ans;
    }
    int checkRecord(int n) {
        memset(t,-1,sizeof(t));

        return solve(0,n,0,0);
        // 0th index is present ,1nd index is n,2rd index is Absent,3rd index is late,


    }
};