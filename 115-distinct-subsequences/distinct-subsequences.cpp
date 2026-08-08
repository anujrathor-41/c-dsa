class Solution {
public:
int tt[1001][1001];

int solve(string &s,string &t,int m,int n){
    
    if(n==0) return 1;
    if(m==0) return 0;// target is zero ,it came after
    if(tt[m][n] != -1) return tt[m][n];

    if(s[m-1]==t[n-1]){
        return tt[m][n]= solve(s,t,m-1,n-1)+solve(s,t,m-1,n);
    }else{
        return tt[m][n]=solve(s,t,m-1,n);
    }
    
}
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        memset(tt,-1,sizeof(tt));
        return solve(s,t,m,n);
    }
};