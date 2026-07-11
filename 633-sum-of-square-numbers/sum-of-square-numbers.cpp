class Solution {
public:
    bool judgeSquareSum(int c) {
        long  l=0;
        long long r=sqrt(c);
        long long curr;
        while(l<=r){
            curr= (l*l )+ (r*r);
            if(curr<c){
                l++;
            }else if(curr>c){
                r--;
            }else{
                return true;
            }
        }
        return false;
    }
};