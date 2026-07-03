class Solution {
public:
int t[101][10001];
    int solve(int W,vector<int> & coins,int n){
        if(n==0) return INT_MAX-1;
        if(W==0) return  0;

        if(t[n][W]!=-1) return t[n][W];
        if(coins[n-1]<=W){
            return t[n][W]=min(1 + solve(W-coins[n-1],coins,n) , solve(W,coins,n-1));
        }else{
            return t[n][W]=solve(W,coins,n-1);
        }

    }
    int numSquares(int n) {
        vector<int> coins;
        for(int i=1;i*i<=n;i++){
            coins.push_back(i*i);// it gives perfect square
        }
        memset(t,-1,sizeof(t));
        return solve(n,coins,coins.size());// n mera given aur vo capacity hai hai and coins.size() alag n hai nahi to ans galat ayega
        
    }
};