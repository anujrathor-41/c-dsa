class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;

        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]-'a']--;
            if(mp[ransomNote[i]-'a']<0){
                return false;
            }
        }

        return true;
    }
};