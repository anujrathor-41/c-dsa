class Solution {
public:

int t[501][501];
    int lcs(string & s1 ,string & s2,int m,int n ){
        if(m==0 || n==0) return 0;

        if(t[m][n]!=-1) return t[m][n];

        if(s1[m-1]== s2[n-1]) {
            return t[m][n]= 1 + lcs(s1,s2,m-1,n-1);
        } else{
            return t[m][n]=  max(lcs(s1,s2,m-1,n) ,lcs(s1,s2,m,n-1));
        }
    }
    int minInsertions(string s) {
        
        // like minimum # of deletion
        // lcs->lps

        int m=s.size();
        int n=s.size();
        memset(t,-1,sizeof(t));
        string s2=s;
        reverse(s2.begin(),s2.end());
        return m - lcs(s,s2,m,n);

    }
};