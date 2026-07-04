class Solution {
public:
int tt[101][10001];
int lcs(string &s,string t,int m,int n){
    if(m==0 || n==0) return 0;

    if(tt[m][n]!=-1) return tt[m][n];

    if(s[m-1]==t[n-1]){
        return tt[m][n]= 1+ lcs(s,t,m-1,n-1);
    }else{
        return tt[m][n]= max(lcs(s,t,m-1,n) ,lcs(s,t,m,n-1));
    }

}
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        memset(tt,-1,sizeof(tt));
    if(lcs(s,t,m,n)==s.size()){
        return true;
    }
    else{
        return false;
    }
        
    }
};