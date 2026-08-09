class Solution {
public:
    int search(vector<int>& arr, int tar) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==tar){
                return mid;
            }else if(arr[mid]<tar){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
};