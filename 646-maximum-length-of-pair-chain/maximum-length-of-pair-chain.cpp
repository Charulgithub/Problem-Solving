class Solution {
public:
    int solve(int ind, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp){
        int n = pairs.size(); 
        if(ind == n) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int nottake = solve(ind+1, prev, pairs, dp);
        int take = -1e9 ;
        if(prev == -1 || pairs[ind][0] > pairs[prev][1]){
            take = 1 + solve(ind+1, ind, pairs, dp);
        }
        return dp[ind][prev+1] = max(take, nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, pairs, dp);
    }
};