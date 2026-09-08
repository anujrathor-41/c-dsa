// class Solution {
// public:

//     bool isPalindrome(string &s, int start, int end) {

//         while(start < end) {

//             if(s[start] != s[end])
//                 return false;

//             start++;
//             end--;
//         }

//         return true;
//     }

//     void solve(string &s, int idx,
//                vector<string>& temp,
//                vector<vector<string>>& ans) {

//         // poora string partition ho gaya
//         if(idx == s.size()) {
//             ans.push_back(temp);
//             return;
//         }

//         for(int i = idx; i < s.size(); i++) {

//             // idx -> i palindrome hai?
//             if(isPalindrome(s, idx, i)) {

//                 // substring
//                 string str = s.substr(idx, i - idx + 1);

//                 // choose
//                 temp.push_back(str);

//                 // next partition
//                 solve(s, i + 1, temp, ans);

//                 // undo
//                 temp.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {

//         vector<vector<string>> ans;
//         vector<string> temp;

//         solve(s, 0, temp, ans);

//         return ans;
//     }
// };




// class Solution { 
// public: 
 
//     bool isPalindrome(string &s, int start, int end) { 
 
//         while(start < end) { 
 
//             if(s[start] != s[end]) 
//                 return false; 
 
//             start++; 
//             end--; 
//         } 
 
//         return true; 
//     } 
 
//     void solve(string &s, int idx, 
//                vector<string> temp, 
//                vector<vector<string>>& ans) { 
 
//         if(idx == s.size()) { 
//             ans.push_back(temp); 
//             return; 
//         } 
 
//         for(int i = idx; i < s.size(); i++) { 
 
//             if(isPalindrome(s, idx, i)) { 
 
//                 string str = s.substr(idx, i - idx + 1); 
 
//                 // Fresh copy for this choice 
//                 vector<string> newTemp = temp; 
 
//                 newTemp.push_back(str); 
 
//                 solve(s, i + 1, newTemp, ans); 
//             } 
//         } 
//     } 
 
//     vector<vector<string>> partition(string s) { 
 
//         vector<vector<string>> ans; 
//         vector<string> temp; 
 
//         solve(s, 0, temp, ans); 
 
//         return ans; 
//     } 
// };


// class Solution { 
// public: 
 
//     bool isPalindrome(string &s, int start, int end) { 
 
//         while(start < end) { 
 
//             if(s[start] != s[end]) 
//                 return false; 
 
//             start++; 
//             end--; 
//         } 
 
//         return true; 
//     } 
 
//     void solve(string &s, int idx, 
//                vector<string> temp, 
//                vector<vector<string>>& ans) { 
 
//         if(idx == s.size()) { 
//             ans.push_back(temp); 
//             return; 
//         } 
 
//         for(int i = idx; i < s.size(); i++) { 
 
//             if(isPalindrome(s, idx, i)) { 
 
//                 string str = s.substr(idx, i - idx + 1); 
 
//                 // Fresh copy for this choice 
//                 // vector<string> newTemp = temp; 
 
//                 // newTemp.push_back(str); 
//                 temp.push_back(str);
//                 solve(s, i + 1, temp, ans); 
//                 temp.pop_back();
//             } 
//         } 
//     } 
 
//     vector<vector<string>> partition(string s) { 
 
//         vector<vector<string>> ans; 
//         vector<string> temp; 
 
//         solve(s, 0, temp, ans); 
 
//         return ans; 
//     } 
// };

class Solution { 
public: 
 
    bool isPalindrome(string &s, int start, int end) { 
 
        while(start < end) { 
 
            if(s[start] != s[end]) 
                return false; 
 
            start++; 
            end--; 
        } 
 
        return true; 
    } 
 
    void solve(string &s, int idx, 
               vector<string>& temp, 
               vector<vector<string>>& ans) { 
 
        if(idx == s.size()) { 
            ans.push_back(temp); 
            return; 
        } 
 
        for(int i = idx; i < s.size(); i++) { 
 
            if(isPalindrome(s, idx, i)) { 
 
                string str = s.substr(idx, i - idx + 1); 
 
                // Fresh copy for this choice 
                // vector<string> newTemp = temp; 
 
                // newTemp.push_back(str); 
                temp.push_back(str);
                solve(s, i + 1, temp, ans); 
                temp.pop_back();
            } 
        } 
    } 
 
    vector<vector<string>> partition(string s) { 
 
        vector<vector<string>> ans; 
        vector<string> temp; 
 
        solve(s, 0, temp, ans); 
 
        return ans; 
    } 
};