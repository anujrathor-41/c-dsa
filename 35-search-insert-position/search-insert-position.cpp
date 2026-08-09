class Solution {
public:
    int searchInsert(vector<int>& arr, int tar) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]>=tar){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return s;
    }
};