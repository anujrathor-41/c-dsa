class Solution {
public:

  void solve(vector<int> &v,int k,int ind,int &ans){
      if(v.size()==1){
          ans=v[0];
          return ;
      }
      ind=(ind+k)% v.size();
      v.erase(v.begin()+ind);// maro
      solve(v,k,ind,ans);
      
  }
    int findTheWinner(int n, int k) {
         vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k=k-1;
        int ind=0;
        int ans=-1;//mujhe last ka vec[0] lake dega
        solve(v,k,ind,ans);
        return ans;
    }
};