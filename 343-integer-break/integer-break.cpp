class Solution {
public:
    int t[60][60];

    int solve(int n, int W, vector<int> &val, vector<int> &wt) {

        if (W == 0)
            return 1;          // product identity

        if (n == 0)
            return 0;

        if (t[n][W] != -1)
            return t[n][W];

        int notTake = solve(n - 1, W, val, wt);

        int take = 0;

        if (wt[n - 1] <= W) {

            // Continue taking numbers
            if (solve(n, W - wt[n - 1], val, wt) != 0)
                take = val[n - 1] * solve(n, W - wt[n - 1], val, wt);
        }

        return t[n][W] = max(take, notTake);
    }

    int integerBreak(int n) {

        vector<int> wt, val;

        // numbers from 1 to n-1
        for (int i = 1; i < n; i++) {
            wt.push_back(i);
            val.push_back(i);
        }

        memset(t, -1, sizeof(t));

        return solve(n - 1, n, val, wt);
    }
};