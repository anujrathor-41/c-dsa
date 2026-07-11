class Solution {
public:
    int minPairSum(vector<int>& nums) {
    // Pair all numbers so that the maximum pair sum is as small as possible.
     int n=nums.size();
    sort(nums.begin(),nums.end());
     int i=0;
     int j=n-1;
     int mx=INT_MIN;
     while(i<=j){
         int sum=nums[i] + nums[j];
         mx=max(mx,sum);
           i++;
           j--;

     }   
     return mx;
    }
};