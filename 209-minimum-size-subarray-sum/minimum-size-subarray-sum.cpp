class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=0;
        int mn=INT_MAX;
        int sum=0;

        while(j<n){
            // cal
            sum=sum+arr[j];
            

            if(sum<k){
                j++;
            }
            else if(sum>=k){

                while(sum>=k){
                    mn=min(mn,j-i+1);

                    sum =sum-arr[i];
                    i++;
                }
                j++;
                
            }
            
            
        }
        if(mn==INT_MAX){
            return 0;
        }else {
            return mn;
        }
    }
};// wrong


// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {

//         int n = nums.size();
//         int i = 0;
//         int j = 0;
//         int sum = 0;
//         int mn = INT_MAX;

//         while (j < n) {

//             // calculation
//             sum += nums[j];

//             if (sum < target) {
//                 j++;
//             }
//             else if (sum >= target) {

//                 while (sum >= target) {

//                     mn = min(mn, j - i + 1);

//                     sum -= nums[i];
//                     i++;
//                 }

//                 j++;
//             }
//         }

//         if(mn==INT_MAX){
//             return 0;
//         }else {
//             return mn;
//         }
//     }
// };