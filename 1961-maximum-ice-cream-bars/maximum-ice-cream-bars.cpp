class Solution {
public:
    int maxIceCream(vector<int>& arr, int coins) {
        int n=arr.size();
        int cnt=0;
        int sum=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(sum + arr[i] <=coins){
                cnt++;
                sum=sum +arr[i];
                
            }
           
        }
        return cnt;
    }
};