class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> t(n);
        t[0]=nums[0];
        for(int i=1;i<n;i++){
            t[i]= t[i-1] + nums[i];
        }
        return t;
    }
};