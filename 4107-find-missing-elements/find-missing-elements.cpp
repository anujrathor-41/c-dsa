class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
        int mn= *min_element(arr.begin(),arr.end());
        int mx= *max_element(arr.begin(),arr.end());

        unordered_set<int> st(arr.begin(),arr.end()) ;
        vector<int> ans;
        for( int i=mn;i<=mx;i++){
            if(st.find(i)==st.end()){// nahi mila set main to set main daal do
                
                ans.push_back(i);
            }
        }
        return ans;

    }
};