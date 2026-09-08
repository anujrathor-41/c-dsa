// class Solution {
// public:
// int t[301];
//     bool solve(string s, vector<string>& word, int idx) {
//         if (idx == s.size()) {
//             return true;
//         }
//         if(t[idx]!=-1) return t[idx];
//         for (int i = idx; i < s.size(); i++) {

//             string temp = s.substr(idx, i - idx + 1);

//             if (find(word.begin(), word.end(), temp) != word.end()) {

//                 if (solve(s, word, i + 1))
//                    return  t[idx]= true;
//             }
//         }
//          return t[idx] =false;
//     }
   

//  bool wordBreak(string s, vector<string>& word) {
//     memset(t,-1,sizeof(t));
//     return solve(s, word, 0);
// }
// }
// ;

class Solution {
public:
int t[301];
    bool solve(string s, vector<string>& word, int idx) {
        if (idx == s.size()) {
            return true;
        }
        if(t[idx]!=-1) return t[idx];
        for (int i = idx; i < s.size(); i++) {

            string temp = s.substr(idx, i - idx + 1);

            if (count(word.begin(), word.end(), temp) >0) {

                if (solve(s, word, i + 1))
                   return  t[idx]= true;
            }
        }
         return t[idx] =false;
    }
   

 bool wordBreak(string s, vector<string>& word) {
    memset(t,-1,sizeof(t));
    return solve(s, word, 0);
}
}
;