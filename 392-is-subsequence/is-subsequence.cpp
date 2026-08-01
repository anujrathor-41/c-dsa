class Solution {
public:
    bool isSubsequence(string s, string t) {
     int i=0;
     int j=0;
     while(j<t.size()){
        if(i<s.size() && s[i]==t[j]){
            i++;
        }
        j++;
     }
     if(i==s.size()){
        return true;
     }else {
        return false;
     }

    }
};