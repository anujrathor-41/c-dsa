class Solution {
public:
    int longestSubarray(vector<int>& arr) {
         int n=arr.size();
        int i=0;
        int j=0;
        int cnt1=0;
        int k=1;
        int mx=INT_MIN;
        while(j<n){
            if(arr[j]==0){
                cnt1++;
            }
            while(cnt1>k){
                if(arr[i]==0){
                    cnt1--;
                }
                i++;
            }
            mx= max(mx,j-i);
            j++;
        }
        return mx;
    }
};