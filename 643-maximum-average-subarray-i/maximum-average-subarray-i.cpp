class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int n=arr.size();

     int i=0;
     int j=0;
     double mx=INT_MIN;
     double sum=0;
     int start=0;

     while(j<n){
        sum=sum+arr[j];

        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            mx=max(mx,sum/k);
            start=i;

             sum=sum-arr[i];
             i++;
             j++;
        }
     }
     return mx;

    }
};