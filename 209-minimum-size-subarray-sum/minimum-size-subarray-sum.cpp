// class Solution {
// public:
//     int minSubArrayLen(int k, vector<int>& arr) {
//         int n=arr.size();
//         int i=0;
//         int j=0;
//         int mn=INT_MAX;
//         int sum=0;

//         while(j<n){
//             // cal
//             sum=sum+arr[j];
//             j++;

//             if(sum<k){
//                 j++;
//             }
//             else if(sum==k){
//                 mn=min(mn,j-i+1);
//                 j++;
//             }
//             else if(sum>k){
//                 while(sum>k){
//                     sum=sum-arr[i];
//                     i++;
//                 }
//                 j++;
//             }
//         }
//         return mn;
//     }
// };


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int mn = INT_MAX;

        while (j < n) {

            // calculation
            sum += nums[j];

            if (sum < target) {
                j++;
            }
            else if (sum >= target) {

                while (sum >= target) {

                    mn = min(mn, j - i + 1);

                    sum -= nums[i];
                    i++;
                }

                j++;
            }
        }

        return (mn == INT_MAX) ? 0 : mn;
    }
};