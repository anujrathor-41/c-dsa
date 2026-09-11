class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<arr.size()-2;i++){
            int a=arr[i];
            int b=arr[i+1];
            int c=arr[i+2];
            if(a<b+c){
                return a+b+c;
            }
        }
        return 0;
    }
};