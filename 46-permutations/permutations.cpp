class Solution {
public:
    void solve(vector<int> arr,vector<int> temp,vector<vector<int>> &res,int idx){
        int n=arr.size();
        if(idx==n) {
            res.push_back(temp);
            return ;
        }

        for(int i=idx;i<n;i++){
            swap(arr[idx],arr[i]);
            temp.push_back(arr[idx]);
            solve(arr,temp,res,idx+1);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(arr,temp,res,0);
        return res;
    }
};