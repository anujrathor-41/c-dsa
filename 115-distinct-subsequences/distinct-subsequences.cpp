class Solution {
public:

    int t[1001][1001];

    int solve(string &s, string &target, int m, int n)
    {
        // Target becomes empty
        if(n == 0)
            return 1;

        // Source becomes empty
        if(m == 0)
            return 0;

        if(t[m][n] != -1)
            return t[m][n];

        if(s[m-1] == target[n-1])
        {
            return t[m][n] =
                solve(s, target, m-1, n-1) +
                solve(s, target, m-1, n);
        }
        else
        {
            return t[m][n] =
                solve(s, target, m-1, n);
        }
    }

    int numDistinct(string s, string target)
    {
        memset(t, -1, sizeof(t));

        return solve(s, target, s.size(), target.size());
    }
};