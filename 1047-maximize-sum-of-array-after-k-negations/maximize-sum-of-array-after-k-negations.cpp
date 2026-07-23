class Solution {
public:
    int largestSumAfterKNegations(vector<int>& arr, int k) {
        int n=arr.size();

        sort(arr.begin(),arr.end());
        for(int i=0;i<n && k>0 ;i++){
            if(arr[i]<0){
                arr[i]= -arr[i];
                k--;
            }
            
        }// -ve to positive
        int sum=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            sum += arr[i];
            mn=min(abs(arr[i]),mn); 
        }
        if(k%2==1){//odd hai
            sum -= 2*mn;
        }
        return sum;

    }
};