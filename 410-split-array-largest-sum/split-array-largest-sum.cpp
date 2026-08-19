class Solution {
public:
    int splitArray(vector<int>& arr, int hr) {
        int s = *max_element(arr.begin(), arr.end());
        // int e = *accumulate(arr.begin(), arr.end(),0);
        int e = accumulate(arr.begin(), arr.end(), 0);

        int ans = 0;
       
        while (s <= e) {
            int mid = (s + e) / 2;
            if(arr.size()<hr){
                return -1;
            }
             int curr = 0;
        int days = 1;
            for (int i = 0; i < arr.size(); i++) {
                if (curr + arr[i] <= mid) {
                    curr = curr + arr[i];
                } else {
                    days++;
                    curr = arr[i];
                }
            }

            if (days <= hr) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};