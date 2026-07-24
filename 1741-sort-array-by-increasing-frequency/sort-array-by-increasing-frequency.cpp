class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        int n=arr.size();

        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> maxH;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto i =mp.begin();i!=mp.end();i++ ){
            maxH.push({-i->second,i->first});

            
        }
        while(maxH.size()>0){
            int freq= -maxH.top().first;
            int ele=maxH.top().second;

            for(int i=1;i<=freq;i++){
                ans.push_back(ele);
            }
            maxH.pop();
        }
      
        return ans;
    }
};