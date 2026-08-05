class Solution {
public:
    int t[501][501];
    int lcs(vector<int>& arr1, vector<int>& arr2,int n,int m){
        if(n==0 || m==0) return 0;

        if(t[n][m]!=-1) return t[n][m];
        if(arr1[n-1]==arr2[m-1]){
          return t[n][m]=  1 + lcs(arr1,arr2,n-1,m-1);
        }
        else{
          return t[n][m]=  max(lcs(arr1,arr2,n-1,m) , lcs(arr1,arr2,n,m-1));
        }
    }
    int maxUncrossedLines(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        memset(t,-1,sizeof(t));
        return lcs(arr1,arr2,n,m);
    }
};