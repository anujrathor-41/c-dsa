class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
          int n=nums.size();
        vector<int> t(n), tt(n);
        vector<int> ans(n);
        t[0]=nums[0];
        tt[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            t[i]=t[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            tt[i]= tt[i+1] +nums[i];
        }
        for(int i=0;i<n;i++){
             ans[i] =abs(t[i]-tt[i]);
        }
        return ans;
        
    }
};