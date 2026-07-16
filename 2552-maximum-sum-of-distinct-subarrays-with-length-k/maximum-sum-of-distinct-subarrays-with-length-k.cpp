class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int j=0;
        long long  mx=0;
        long long sum=0;

        unordered_map<int,int> mp;

        while(j<n ){
            sum =sum + arr[j];
            mp[arr[j]]++;

            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){

                if(mp.size()==k){// mp.size=# of unique character
                     mx=max(sum,mx);
                }
               

                sum=sum-arr[i];//slide the window
                mp[arr[i]]--;

                if(mp[arr[i]]==0){// dono ki value same then remove from mp
                // freq ==0 yani kuch bhi nahi hai mp main means 
                // unique charater hata diye map se 
                    mp.erase(arr[i]);
                }
                i++;
                j++;
            }
        }
        return mx;
    }
};