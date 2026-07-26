class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int m=arr.size();
        priority_queue<int> maxH;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxH.push(arr[i][j]);

                if(maxH.size()>k){
                    maxH.pop();
                }
            }
        }
        return maxH.top();
    }
};