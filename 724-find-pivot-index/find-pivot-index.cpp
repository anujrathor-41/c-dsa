// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> t(n), tt(n);
//         t[0]=nums[0];
//         tt[n-1]=nums[n-1];

//         for(int i=1;i<n;i++){
//             t[i]=t[i-1]+nums[i];
//         }
//         for(int i=n-2;i>=0;i--){
//             tt[i]= tt[i+1] +nums[i];
//         }
//         for(int i=0;i<n;i++){
//             if(t[i]==tt[i]){
//                 return i;
//             }
//         }
//         return -1;
        
//     }
// };
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
       int left=0;
       int right=0;
       for(int i=0;i<n;i++){
        right=right+nums[i];// sum
       }
       for(int i=0;i<n;i++){
        right =right-nums[i];//sum-arr[i]
        if(left==right){
            return i;
        }
        left=left+nums[i];
       }
        return -1;
        
    }
};