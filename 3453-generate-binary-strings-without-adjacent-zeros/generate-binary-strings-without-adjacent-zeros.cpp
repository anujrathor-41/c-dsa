class Solution {
public:

    void solve(string op,int n,vector<string> &ans){
        if(n==0){
            ans.push_back(op);
            return ;
        }
        string op1=op;
        op1.push_back('1');
        solve(op1,n-1,ans);

        // add 0
        if(op.empty() || op.back()=='1' ){
             string op2=op;
            op2.push_back('0');
            solve(op2,n-1,ans);
        }
    }
    vector<string> validStrings(int n) {
        string op;
        vector<string> ans;
        solve(op,n,ans);
        return ans;
    }
};