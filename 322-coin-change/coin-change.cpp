class Solution {
public:
int t[20][10001];

    int solve(vector<int> &coins,int W,int n){
        if(n==0) return INT_MAX-1;
        if(W==0) return 0;// 1 possible way

        if(t[n][W]!=-1) return t[n][W];

        if(coins[n-1]<=W){
        return t[n][W]= min(1 + solve(coins,W-coins[n-1] ,n) , solve(coins,W,n-1) );
        }else{
           return t[n][W] =solve(coins,W,n-1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
         int ans=solve(coins,amount,coins.size()) ;
         if(ans==INT_MAX-1){
            return -1;
         }else{
            return ans;
         }

        
    }
};