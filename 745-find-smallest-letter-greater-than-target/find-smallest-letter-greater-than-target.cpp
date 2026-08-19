class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char tar) {
        int s=0;
        int n=arr.size();
        int e=n-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]<=tar){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return arr[s%n];
    }
};