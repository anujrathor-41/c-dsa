class Solution {
public:
    void solve(vector<int> & arr ,int target,int idx,vector<int> curr,vector<vector<int>> & res){
        if(target==0){
            res.push_back(curr);
            return ;

        }
        if(target<0 || idx==arr.size()){
            return ;
        }
        vector<int> temp=curr;
        temp.push_back(arr[idx]);
        solve(arr,target-arr[idx],idx,temp,res);
        solve(arr,target,idx+1,curr,res);
    } 

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        solve(arr,target,0,{},res);
        return res;

    }
};