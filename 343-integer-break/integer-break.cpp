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

        if (wt[n - 1] <= W) {

           return  t[n][W]= max(val[n-1] * solve(n, W-wt[n-1] ,val,wt), solve(n-1,W,val,wt));
           
        }
        else{
           return t[n][W]= solve(n-1,W,val,wt);
        }

        
    }

    int integerBreak(int n) {

        vector<int> wt, val;

        // numbers from 1 to n-1
        for (int i = 1; i < n; i++) {
            wt.push_back(i);
            val.push_back(i);
        }

        memset(t, -1, sizeof(t));

        return solve(val.size() , n, val, wt);
    }
};