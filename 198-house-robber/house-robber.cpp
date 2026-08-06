class Solution {
public:
int t[101];
int solve(vector<int> & arr,int n){
    if(n<=0) return 0;

    if(t[n]!=-1) return t[n];

    return t[n] =max(solve(arr,n-2)+ arr[n-1],solve(arr,n-1));
}
    int rob(vector<int>& arr) {
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,n);
    }
};