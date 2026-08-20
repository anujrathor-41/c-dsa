class Solution {
public:

    int t[105][105];

    int solve(vector<int>& cuts, int i, int j) {

        // no cut between i and j
        if (i + 1 >= j) {
            return 0;
        }

        // already calculated
        if (t[i][j] != -1) {
            return t[i][j];
        }

        int ans = INT_MAX;

        // k = last cut
        for (int k = i + 1; k <= j - 1; k++) {

            int left = solve(cuts, i, k);

            int right = solve(cuts, k, j);

            int current = cuts[j] - cuts[i];

            int total = left + right + current;

            ans = min(ans, total);
        }

        return t[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        memset(t, -1, sizeof(t));

        return solve(cuts, 0, cuts.size() - 1);
    }
};