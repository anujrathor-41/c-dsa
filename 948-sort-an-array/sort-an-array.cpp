class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n=arr.size();

        priority_queue<int,vector<int>,greater<int>> minH;
        vector<int> ans;
        for(int i=0;i<n;i++){
            minH.push(arr[i]);
            if(minH.size()>n){
                ans.push_back(minH.top());
                minH.pop();
            }
        }
        while(minH.size()>0){
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};