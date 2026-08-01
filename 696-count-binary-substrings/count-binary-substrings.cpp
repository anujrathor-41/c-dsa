class Solution {
public:
    int countBinarySubstrings(string arr) {
        int n=arr.size();
        int cnt=1;//count of group
        int ans=0;
        vector<int> group;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                cnt++;
            }else{
                group.push_back(cnt);
                cnt=1;
            }
        }
        // store last group count
        group.push_back(cnt);

        for(int i=0;i<group.size()-1;i++){
            ans +=min(group[i],group[i+1]);
        }
        return ans;
    }
};