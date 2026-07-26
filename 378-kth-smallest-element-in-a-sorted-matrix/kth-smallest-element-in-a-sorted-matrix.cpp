class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n=arr.size();

        priority_queue<int> maxH;
        for(int i=0;i<n*n;i++){
            int row=i/n;
            int col=i%n;
            maxH.push(arr[row][col]);

            if(maxH.size()>k){
                maxH.pop();
            }
        }
        return maxH.top();
    }
};