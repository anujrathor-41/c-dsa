class Solution {
public:

const int MOD = 1e9 + 7;

    long long dp[100005];
    int last[100005];

    long long solve(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        long long ans = (2LL * solve(n - 1)) % MOD;

        if (last[n] != -1) {
            ans = (ans - solve(last[n] - 1) + MOD) % MOD;
        }

        return dp[n] = ans;
    }
    int distinctSubseqII(string str) {
         int n = str.size();

        memset(dp, -1, sizeof(dp));
        memset(last, -1, sizeof(last));

        unordered_map<char, int> mp;

        // Store previous occurrence (1-based indexing)
        for (int i = 1; i <= n; i++) {
            char ch = str[i - 1];

            if (mp.find(ch) != mp.end()) {
                last[i] = mp[ch];
            }

            mp[ch] = i;
        }

        return (solve(n)-1+MOD)%MOD;
    }
};