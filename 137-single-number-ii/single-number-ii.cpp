class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                ans=it.first;
            }
        }
        return ans;
    }
};