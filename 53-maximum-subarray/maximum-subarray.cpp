class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currSum=0;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            currSum= currSum + nums[i];

            if(currSum<nums[i]){
                currSum=nums[i];
            }
            mx=max(currSum,mx);
        }
        return mx;
    }
};