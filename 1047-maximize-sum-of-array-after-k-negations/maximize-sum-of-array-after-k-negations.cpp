class Solution {
public:
    int largestSumAfterKNegations(vector<int>& arr, int k) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());

        for(int i=0;i<n && k>0;i++){
            if(arr[i]<0){
                arr[i]=-arr[i];
                k--;
            }
        }// neg to pos
        int sum=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            mn=min(abs(arr[i]),mn);// we get min among arr[i]
        }

        if(k%2==1){// 6 is min in arr then 
        // we have to disappear positive 6 and then add negative 6 that's why 2*mn
            sum -=2*mn;
        }
        return sum;
    }
};