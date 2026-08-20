class Solution {
public:

    int t[55][55];

    int solve(vector<int>& values, int i, int j) {

        if(i + 1 >= j) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int ans = INT_MAX;

        for(int k = i + 1; k <= j - 1; k++) {

            int left = solve(values, i, k);

            int right = solve(values, k, j);

            int current = values[i] * values[k] * values[j];

            int total = left + right + current;

            ans = min(ans, total);
        }

        return t[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {

        memset(t, -1, sizeof(t));

        int n = values.size();

        return solve(values, 0, n - 1);
    }
};