class Solution {
public:

    int bfs(queue<string>& q,
            unordered_set<string>& st,
            unordered_set<string>& vis,
            string target) {

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                string str = q.front();
                q.pop();

                if (str == target)
                    return level;

                for (int i = 0; i < 4; i++) {

                    // Forward move
                    string str2 = str;

                    if (str2[i] == '9')
                        str2[i] = '0';
                    else
                        str2[i]++;

                    if (!st.count(str2) && !vis.count(str2)) {
                        vis.insert(str2);
                        q.push(str2);
                    }

                    // Backward move
                    str2 = str;

                    if (str2[i] == '0')
                        str2[i] = '9';
                    else
                        str2[i]--;

                    if (!st.count(str2) && !vis.count(str2)) {
                        vis.insert(str2);
                        q.push(str2);
                    }
                }
            }

            level++;
        }

        return -1;
    }

    int openLock(vector<string>& Adj, string target) {

        unordered_set<string> st;
        unordered_set<string> vis;
        queue<string> q;

        for (string s : Adj)
            st.insert(s);

        if (st.count("0000"))
            return -1;

        q.push("0000");
        vis.insert("0000");

        return bfs(q, st, vis, target);
    }
};