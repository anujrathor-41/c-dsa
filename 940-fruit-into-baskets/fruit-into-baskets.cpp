class Solution {
public:
    int totalFruit(vector<int>& fruits) {// variable size window
        int n=fruits.size();
        int i=0;
        int j=0;
        int mx=0;

        unordered_map<int,int> mp;
        
        while(j<n){
            mp[fruits[j]]++;

            if(mp.size()<2){
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()==2){// hit the window
                //  ans<-cal
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[i]]--;

                    if(mp[fruits[i]]==0){// freq zero then -> map main se uda denge
                        mp.erase(fruits[i]);// remove cal of i
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};