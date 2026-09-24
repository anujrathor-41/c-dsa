class Solution {
public:
int t[1001];
int solve(vector<int> &arr,int n){
    if(n==0) return 0;
    if(n==1) return 0 ; 

    if(t[n]!=-1) return t[n];

    return t[n]= min(arr[n-1] + solve(arr,n-1) ,arr[n-2] +solve(arr,n-2)); 

}
    int minCostClimbingStairs(vector<int>& arr) {
        memset(t,-1,sizeof(t));
        return solve(arr,arr.size());
    }
};