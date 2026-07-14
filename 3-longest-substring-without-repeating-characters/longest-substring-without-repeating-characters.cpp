class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     // means with all unique character
     //sliding window  variable size
     // match with k unique character
    
    int n=s.size();
     int i=0;
     int j=0;

     unordered_map<char,int> mp;

     int mx=0;
     int kk=mp.size();

     while(j<n){

     
        mp[s[j]]++;// freq count without check in mp

        // if(mp.size()<k){ never kabhi bhi follow nahi hogi condition
        // thoda sa dimag lagaoge to
        //     j++;
        // }
        if(mp.size()==j-i+1){
            // ans <- cal
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()<j-i+1){
            
            while(mp.size()<j-i+1){
                mp[s[i]]--;
                
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                 i++;// i++ karne se pahle remove i ki cal
            } 
            j++;
        }
     } 
     return mx;  
    }
    
};