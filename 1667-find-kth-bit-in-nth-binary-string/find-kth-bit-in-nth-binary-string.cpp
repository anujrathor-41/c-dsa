class Solution {
public:
    char findKthBit(int n, int k) {
        
        if(n==1) return '0';

        int len=pow(2,n)-1;
        int mid=(len/2 +1) ;


        if(mid==k){
            return '1';

        }
        else if(k<mid){
            return findKthBit(n-1,k);
        }
        
        char bit= findKthBit(n-1,len-k+1);// it will give you mirror
        
        if(bit=='0'){
            return '1';
        }else {
            return '0';
        }
    }
};