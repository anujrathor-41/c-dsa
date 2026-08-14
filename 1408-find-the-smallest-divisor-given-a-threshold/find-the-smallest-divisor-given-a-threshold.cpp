class Solution {
public:
    int smallestDivisor(vector<int>& arr, int hr) {
        int e= *max_element(arr.begin(),arr.end());
        int s=1;
       
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            long long curr=0;
            for(int i=0;i<arr.size();i++){
                 curr=curr+ ceil((double) arr[i]/mid);
            }
            if(curr<=hr){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};