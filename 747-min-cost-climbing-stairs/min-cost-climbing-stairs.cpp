class Solution {
public:
int t[1001];
int solve(vector<int> &cost ,int n){
    if(n==0 || n==1) return 0;
    
    

    if(t[n]!=-1) return t[n];
     return t[n]= min(solve(cost,n-1)+cost[n-1] ,solve(cost,n-2)+cost[n-2]);


}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(t,-1,sizeof(t));
        return solve(cost,n);
       
    }
};