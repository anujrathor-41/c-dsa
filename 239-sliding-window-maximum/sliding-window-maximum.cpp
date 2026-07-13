class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans;
        deque<int> l;
        int i=0;
        int j=0;

        while(j<n){
            // #concept jo bhi arr[j] smaller ele main unko list main se hata do and chote ele aaye list main unko hata dunga , arr[j] ko push karne se pahle
            while(!l.empty() && l.back()<arr[j]){// or l.size()>0
                l.pop_back();//pop back karne se pahele chek agar list empty hui to
            }
            l.push_back(arr[j]);
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                // ans <=cal karni hai
                ans.push_back(l.front());// ans

                if(l.front() == arr[i]){
                    l.pop_front();//dono ki val same than remove from list
                }
                i++;
                j++;

            }
        }
        return ans;

    }
};