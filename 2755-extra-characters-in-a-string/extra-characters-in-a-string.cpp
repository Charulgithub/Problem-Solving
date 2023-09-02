class Solution {
public:
    unordered_set<string> st;
    int n;
    
    int solve(int ind, string& s, vector<string>& dictionary, vector<int>& dp){
        if(ind>=n) return 0;
        
        if(dp[ind] != -1) return dp[ind];

        int maxextra = n; //although we want minextra
        string currStr = "";

        for(int i = ind; i<n; i++){
            currStr.push_back(s[i]);
            
            int currExtra = 0;
            if(st.find(currStr) == st.end()){
                currExtra = currStr.length();
            }
            int nextextra = solve(i+1, s, dictionary, dp);
            int total = currExtra + nextextra;
            
            maxextra = min(maxextra, total);
            dp[ind] = maxextra;
        }
        return dp[ind];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        for(auto &word : dictionary){
            st.insert(word);
        }
        vector<int>dp(n+1, -1);
        return solve(0, s, dictionary, dp);
    }
};