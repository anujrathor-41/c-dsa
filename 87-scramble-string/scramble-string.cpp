class Solution {
public:
unordered_map<string,bool> mp;

bool solve(string a, string b){
    if(a.compare(b)==0){
        return true;//no swap
    }
    if(a.length()<=1) return false;//constrint leaf node cant be empty or binary tree


    string key = a ;
    key.push_back(' ');
    key.append(b);// a_b means
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }

    int n=a.length();
    bool flag=false;
    for(int i=1;i<=n-1;i++){// s.substr(start,length)
        //swap case1
         int cond1=  ( solve(a.substr(0,i),b.substr(n-i,i))
            && 
            solve(a.substr(i,n-i),b.substr(0,n-i))
            );

        // swap nahi hua    case 2
          int cond2=  ( solve(a.substr(0,i),b.substr(0,i))
            && 
            solve(a.substr(i,n-i),b.substr(i,n-i))
            );  
        
        
        if(cond1 || cond2){
            flag=true;
            break;
        }
    }
    return mp[key]= flag;

}
    bool isScramble(string a, string b) {
        if(a.length()!=b.length()) return false;
        if(a.size()==0 && b.size()==0) return true;

        return solve(a,b);
    }
};