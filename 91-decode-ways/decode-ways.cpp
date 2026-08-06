class Solution {
public:
    int t[101];

    int solve(string &s, int n) {

        if (n == 0)
            return 1;

        int idx = s.size() - n;

        if (s[idx] == '0')
            return 0;

        if (t[n] != -1)
            return t[n];

        // Take one digit
        int one = solve(s, n - 1);

        // Take two digits
        int two = 0;
        if (n >= 2) {
            int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');

            if (num >= 10 && num <= 26)
                two = solve(s, n - 2);
        }

        return t[n] = one + two;
    }

    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        return solve(s, s.size());
    }
};