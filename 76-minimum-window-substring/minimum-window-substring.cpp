class Solution {
public:
    string minWindow(string s, string t) {
     int n=s.size();
     int i=0;
     int j=0;
     int mn=INT_MAX;
     int start=0;
    
    unordered_map<char,int> mp;
    for(int i=0;i<t.size();i++){
        mp[t[i]]++;
    }
    int cnt=mp.size();
     while(j<n){
        // sath sath cal karni hai
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] ==0){
                cnt--;
            }
        }
        if(cnt>0){
            j++;
        }
        else if(cnt==0){
            while(cnt==0){
               if(j-i+1<mn){
                mn=j-i+1;
                start=i;
               }
            
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;

                    if(mp[s[i]] ==1){
                        cnt++;
                    }
                }
                i++;
            }
            j++;
        }
     }  
     if(mn==INT_MAX){
        return "";
     }
     return s.substr(start,mn); 
    }
};



// class Solution {
// public:
//     string minWindow(string &s, string &p) {

//         int n = s.size();
//         int i = 0;
//         int j = 0;

//         unordered_map<char, int> mp;

//         for (char ch : p)
//             mp[ch]++;

//         int cnt = mp.size();

//         int start = 0;
//         int mn = INT_MAX;

//         while (j < n) {

//             if (mp.find(s[j]) != mp.end()) {
//                 mp[s[j]]--;

//                 if (mp[s[j]] == 0)
//                     cnt--;
//             }

//             if (cnt > 0) {
//                 j++;
//             }
//             else if (cnt == 0) {

//                 while (cnt == 0) {

//                     if (j - i + 1 < mn) {
//                         mn = j - i + 1;
//                         start = i;
//                     }

//                     if (mp.find(s[i]) != mp.end()) {
//                         mp[s[i]]++;

//                         if (mp[s[i]] == 1)
//                             cnt++;
//                     }

//                     i++;
//                 }

//                 j++;
//             }
//         }

//         if (mn == INT_MAX)
//             return "";

//         return s.substr(start, mn);
//     }
// };