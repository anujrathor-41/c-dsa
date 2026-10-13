class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;
        long [] ans = new long[n];
        for(int i = 0;i<n;i++){
            ans[i] = nums[i] * nums[i];
        }
        Arrays.sort(ans);
        long score = 0;
        int k = n/2;
        for(int i =0;i<k;i++){
            score -= ans[i];
        }
        for(int i =k;i<n;i++){
            score += ans[i];
        }
        return score;
    }
}