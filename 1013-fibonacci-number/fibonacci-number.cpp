class Solution {
public:
int t[31];
int solve(int n){
     if(n<=1) return n;

        if(t[n]!=-1) return t[n];
        int left=solve(n-1);
        int right=solve(n-2);
        return left+right;
}
    int fib(int n) {
        memset(t,-1,sizeof(t));
       return solve(n);
    }
};