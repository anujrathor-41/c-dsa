class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int currSum=nums[0];
        for(int i=1;i<n;i++){
            currSum += nums[i];

            if(currSum<nums[i]){
                currSum=nums[i];
            } 
           mx= max(mx,currSum);
        }
        return mx;
    }
};