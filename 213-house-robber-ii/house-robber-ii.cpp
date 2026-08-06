class Solution {
public:
int t[101];

    int solve(vector<int> & arr,int n){
        if(n<=0) return 0;
        if(n==1) return arr[0];
        if(t[n]!=-1) return t[n];

        return t[n] =max(solve(arr,n-2)+arr[n-1],solve(arr,n-1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1(nums.begin()+1,nums.end());
        vector<int> arr2(nums.begin(),nums.end()-1);

        memset(t,-1,sizeof(t));
        

        int ans1=solve(arr1,arr1.size());
        memset(t,-1,sizeof(t));// reset 
        int ans2=solve(arr2,arr2.size());
        return max(ans1,ans2);
    }
};