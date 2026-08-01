class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<int> st;
        int cnt=0;
        for(char ch:jewels){
            st.insert(ch);
        }

        for(char ch:stones){
            if(st.count(ch)){
                cnt++;
            }
        }
        return cnt;
    }
};