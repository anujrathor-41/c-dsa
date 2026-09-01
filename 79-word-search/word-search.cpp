class Solution {
public:
    bool cal(int i,int j,vector<vector<char>>& arr, string word,vector<vector<bool>> &vis , int idx){
        int m=arr.size();
        int n=arr[0].size();
        if(idx==word.size()) return true;
        
        if(i<0 || j<0 || i>=m || j>=n){// boundary check
            return false;
        }
        if(arr[i][j]!=word[idx]) return false;

        if(vis[i][j]==true){//already vis
            return false;
        }


        vis[i][j]=true;
        // d,l,r,u
        bool found = cal(i+1,j,arr,word,vis,idx+1) ||
                    cal(i,j-1,arr,word,vis,idx+1) ||
                    cal(i,j+1,arr,word,vis,idx+1) ||
                    cal(i-1,j,arr,word,vis,idx+1);

        vis[i][j]=false;
        return found;

    }   

    bool exist(vector<vector<char>>& arr, string word) {
        int m=arr.size();
        int n=arr[0].size();

        vector<vector<bool>> vis(m,vector<bool> (n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==word[0]){
                    if(cal(i,j,arr,word,vis,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};