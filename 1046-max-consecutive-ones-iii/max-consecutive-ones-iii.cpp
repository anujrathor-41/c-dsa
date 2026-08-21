// class Solution {
// public:
//     int longestOnes(vector<int>& arr, int k) {// tle dega 0(n^2)
//         int n=arr.size();
       
//         int maxLength=0;
//         for(int i=0;i<n;i++){
//              int cnt=0;
//             for(int j=i;j<n;j++){
//                 if(arr[j]==0){
//                     cnt++;
//                 }
//                 if(cnt<=k){
//                     maxLength=max(maxLength,j-i+1);
//                 }else{
//                     break;
//                 }
//             }
//         }
//         return maxLength;
//     }
// };// tle dega

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
       int maxLength=0;
       int cnt=0;
       int l=0;
       int r=0;
       while(r<n){
        if(arr[r]==0){
            cnt++;
        }
        while(cnt>k){
            if(arr[l]==0){
                cnt--;
            };
            l++;
        }
        maxLength=max(maxLength,r-l+1);
        r++;
       }
       return maxLength;
    }
};