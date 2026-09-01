class Solution {
public:
    void solve(int n,int open,int close,string str,vector<string> & res){
        // pass by value
        if(str.size()==2*n){
            res.push_back(str);
            return ;
        }
        if(open<n){
            solve(n,open+1,close,str + '(',res);
        }
        if(close<open){
            solve(n,open ,close+1,str + ')',res);
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        solve(n,0,0,"", res);
        return res;
    }
};