// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n=numbers.size();
//         int i=0;
//         int j=n-1;

//         while(i<=j){
//             if(numbers[i]+numbers[j]==target){
//                 return {i+1,j+1};
//             }else if(numbers[i]+numbers[j]<target){
//                 i++;
//             }else if(numbers[i]+numbers[j]>target){
//                 j--;
//             }
//         }
//         return {-1};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0;
        int j=n-1;

        while(numbers[i]+numbers[j]!=target){
          if(numbers[i]+numbers[j]<target){
            i++;
          }else if(numbers[i]+numbers[j]>target){
            j--;
          }
        }
        return {i+1,j+1};
    }
};