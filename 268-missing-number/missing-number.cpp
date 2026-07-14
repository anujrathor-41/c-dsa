class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n=nums.size();
        long long sum=n*(n+1)/2;// point hai 

        long long sum1=0;
        for(int i=0;i<nums.size();i++){
            sum1 +=nums[i];
        }
        return (sum-sum1);
    }
};