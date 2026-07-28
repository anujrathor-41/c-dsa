// class Solution {
// public:

//     char solve(int n, int k) {

//         // base case
//         if(n == 1)
//             return 'a';

//         int len = pow(2, n - 1);
//         int mid = len / 2;

//         // left half
//         if(k <= mid){
//             return solve(n - 1, k);
//         }

//         // right half
//         char ch = solve(n - 1, k - mid);

//         // next character
//         if(ch == 'z'){
//             return 'a';
//         }
//         else{
//             return ch + 1;
//         }
//     }

//     char kthCharacter(int k) {

//         int n = 1;
//         int len = 1;

//         while(len < k){
//             len = len * 2;
//             n++;
//         }

//         return solve(n, k);
//     }
// };

class Solution {
public:

    char solve(int n, int k) {
        if(n==1) return 'a';

        int len=pow(2,n-1);
        int mid=len/2;

        if(k<=mid){
            return solve(n-1,k);
        }
            char ch=solve(n-1,k-mid);
        if(ch=='z'){
            return 'a';
        }else{
            return ch+1;
        }
       
    }

    char kthCharacter(int k) {
        int n=1;
        int len=1;

        while(len<k){
            len=len*2;//stirng ki length 8 main kth charcater nikal ke dega
            n++;// next level per pahuchan ke liye
        }
        return solve(n,k);
       
    }
};