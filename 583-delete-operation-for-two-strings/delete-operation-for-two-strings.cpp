class Solution {
public:
int t[501][501];
 int lcs(string &text1,string &text2,int m,int n){
        if(m==0 || n==0) return 0;

        if(t[m][n]!=-1) return t[m][n];

        if(text1[m-1]==text2[n-1]){
            return t[m][n]=1 + lcs(text1,text2,m-1,n-1);
        }
        else{
           return t[m][n]=max(lcs(text1 ,text2,m-1,n),lcs(text1 ,text2,m,n-1));
        }
        return t[m][n];

    }
    int minDistance(string word1, string word2) {
         int m=word1.size();
        int n=word2.size();

        memset(t,-1,sizeof(t));
        int L= lcs(word1,word2,m,n);
        return (m-L + n-L);
        
    }
};