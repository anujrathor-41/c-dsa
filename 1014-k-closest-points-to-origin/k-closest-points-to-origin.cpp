class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> ans;
        vector<int> v;

        priority_queue< pair<int, pair<int,int> >> maxH;

        for(int i=0;i<n;i++){
            maxH.push({arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1],   {arr[i][0],arr[i][1]}});

            if(maxH.size()>k){
                maxH.pop();

            }
        }
        while(maxH.size()>0){
            pair<int,int> p=maxH.top().second;
            ans.push_back({p.first,p.second});// p.first are variable not method
          
            maxH.pop();
        }
        
        return ans;
    }
};