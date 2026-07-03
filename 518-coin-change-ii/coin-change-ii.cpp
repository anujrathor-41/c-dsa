class Solution {
public:
int t[301][5001];

    int solve(int n,int W,vector<int> & coins){//unbounded knapsack variation
        if(n==0) return 0;
        if(W==0) return 1;

        if(t[n][W]!=-1) return t[n][W];

        if(coins[n-1]<=W){// multiple occurance or take         not take
           return t[n][W]=(solve(n,W-coins[n-1],coins) + solve(n-1,W,coins)) ;
        }else{
            return t[n][W]=solve(n-1,W,coins);
        }
        
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(coins.size(),amount,coins);
        
    }
};