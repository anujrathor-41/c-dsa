class Solution {
public:
    string minWindow(string s1, string s2) {
        int i=0;
        int j=0;
        int start=0;
        int mn=INT_MAX;
        unordered_map<char,int> mp;
        for(int i=0;i<s2.size();i++){
            mp[s2[i]]++;
        }
        int cnt=mp.size();
        while(j<s1.size()){
            if(mp.find(s1[j])!=mp.end()){
                mp[s1[j]]--;
                if(mp[s1[j]]==0){
                    cnt--;
                }
            }
            if(cnt>0){
                j++;
            }
            else if(cnt==0){
                while(cnt==0){
                   if(mn>j-i+1){
                    mn=j-i+1;
                    start=i;
                   }
                    
                if(mp.find(s1[i])!=mp.end()){
                    mp[s1[i]]++;
                    if(mp[s1[i]]==1){
                        cnt++;
                    }
                }
                i++;
                }// while close
                j++;
            }
        }
        if(mn==INT_MAX) return "";
        return s1.substr(start,mn);
    }
};