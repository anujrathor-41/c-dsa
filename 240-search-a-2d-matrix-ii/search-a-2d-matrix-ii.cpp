class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        // two pointer
        int i=0;
        int n=arr.size();
        int m=arr[0].size();
        int j=m-1;

        while(i<n && j>=0){
            if(arr[i][j]==tar){
                return true;
            }else if(arr[i][j]<tar){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};