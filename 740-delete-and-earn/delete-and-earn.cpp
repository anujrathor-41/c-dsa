class Solution {
public:
int t[10001];
int solve(vector<int> &nums,int n){
    if(n==0) return 0;
    if(n==1) return nums[1];
    if(t[n]!=-1) return t[n];

    int take=nums[n] + solve(nums,n-2);
    int notTake=solve(nums,n-1);
    return t[n]= max(take,notTake);

}
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();

        int mx=INT_MIN;
        vector<int> points(10001,0);
        // for(int x:nums){
        //     points[x] +=x;
        //     mx=max(mx,x);// largest value present in the arr => mx batayega
        // }// 2,2,3,3,3,4= 4,9,4
        for(int i=0;i<n;i++){
            points[nums[i]] +=nums[i];
            mx=max(mx,nums[i]);
        }

        memset(t,-1,sizeof(t));
        return solve(points,mx);
    }
};