class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=0;i<n;i++){
            minH.push(arr[i]);
            if(minH.size()>k){
                minH.pop();
            }
        }
        return minH.top();
    }
};