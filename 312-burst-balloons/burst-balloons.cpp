class Solution {
public:
    int dp[305][305];

    int solve(vector<int>& a, int i, int j) {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k <= j; k++) {

            ans = max(ans,
                      solve(a, i, k - 1) +
                      solve(a, k + 1, j) +
                      a[i - 1] * a[k] * a[j + 1]);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {

        vector<int> a;
        a.push_back(1);

        for (int x : nums)
            a.push_back(x);

        a.push_back(1);

        memset(dp, -1, sizeof(dp));

        return solve(a, 1, nums.size());
    }
};