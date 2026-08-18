class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        // totally sorted
        int n=arr.size();
         int m=arr[0].size();
        int s=0;
        int e=n*m -1;
       

        while(s<=e){
            int mid=(s+e)/2;
            int row=mid/m;
            int col=mid%m;
            if(arr[row][col]==tar){
                return true;
            }else if(arr[row][col] <tar){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return false;
    }
};