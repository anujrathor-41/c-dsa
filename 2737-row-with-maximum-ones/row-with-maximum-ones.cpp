class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int cnt1=0;
        int mx=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
             cnt1=0;
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1){
                    cnt1++;
                }
                if(cnt1>mx){
                    mx=cnt1;
                    ans=i;
                }
            }
        }
        return {ans,mx};
    }
};