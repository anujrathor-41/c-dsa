class Solution {
public:
    int characterReplacement(string arr, int k) {
        int n=arr.size();
        int i=0;
        int j=0;
        int mx=0;
        int maxFreq=0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[arr[j]]++;
            maxFreq=max(maxFreq,mp[arr[j]]);

            while((j-i+1)-maxFreq >k){// invalid condtion window length-maxFreq
                mp[arr[i]]--;

                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;

    }
};