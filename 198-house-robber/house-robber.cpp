class Solution {
public:
int t[101];
    int solve(vector<int> &nums ,int n){
        if(n==0) return 0;
        if(n==1) return nums[0];

        if(t[n]!=-1) return t[n];

        return t[n] =max(nums[n-1] + solve(nums,n-2), solve(nums,n-1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,n);
    }
};