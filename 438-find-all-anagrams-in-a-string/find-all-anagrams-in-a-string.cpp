class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        int i=0;
        int j=0;
        
        vector<int> ans;
        unordered_map<char,int>  mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int cnt=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    cnt--;
                }
            }
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                if(cnt==0){
                    ans.push_back(i);
                }

                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] ==1){
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;

    }
};