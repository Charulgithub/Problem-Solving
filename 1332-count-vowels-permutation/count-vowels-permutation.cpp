class Solution {
public:

 int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> t;
    long long solve(int ch, int n) {
        if(n == 0) {
            return 1;
        }

        if(t[ch][n] != -1) {
            return t[ch][n];
        }

        /*
            Accoring to question : 
            a -> e
            e -> a, i
            i -> a, e, o, u
            o -> i, u
            u -> a
        */

        if(ch == a) {
            return t[ch][n] = solve(e, n-1) % M;
        } else if(ch == e) {
            return t[ch][n] = (solve(a, n-1) + solve(i, n-1)) % M;
        } else if(ch == i) {
            return t[ch][n] = (solve(a, n-1) + solve(e, n-1) + solve(o, n-1) + solve(u, n-1)) % M;
        } else if(ch == o) {
            return t[ch][n] = (solve(i, n-1) + solve(u, n-1)) % M;
        } else { //ch == u
            return t[ch][n] = solve(a, n-1);
        }


        return t[ch][n] = 0;
    }

    int countVowelPermutation(int n) {
        t.resize(5, vector<long long>(n+1, -1));
        long result = 0;

        result = (result + solve(a, n-1)) % M;
        result = (result + solve(e, n-1)) % M;
        result = (result + solve(i, n-1)) % M;
        result = (result + solve(o, n-1)) % M;
        result = (result + solve(u, n-1)) % M;

        return result;

    }
    // int MOD = (int)(1e9+7);

    // long long solve ( char ch , int n, vector<vector<long long>>& dp){
    //     if ( n == 0) return 1;
    //     if ( dp[ch][n] != -1) return dp[ch][n];

    //     if ( ch == 'a'){
    //         return dp[ch][n] = solve( 'e' , n-1, dp);
    //     } else if( ch == 'e') {
    //         return dp[ch][n] = solve('a' , n-1, dp)+solve('i' , n-1, dp);
    //     } else if ( ch == 'i'){
    //         return dp[ch][n] = solve('a', n-1, dp)+solve('e', n-1, dp)+solve('o', n-1, dp)+solve('u', n-1, dp);
    //     } else if ( ch == 'o'){
    //         return dp[ch][n] = solve ('i', n-1, dp)+solve('u', n-1, dp);
    //     }else{
    //         return dp[ch][n] = solve('a', n-1, dp);
    //     }
    //     return dp[ch][n] = 0;
    // }

    // int countVowelPermutation(int n) {
    //     vector<vector<long long>>dp( 6, vector<long long>(n+1, -1));
    //     long long result = 0;
    //     result += (solve('a', n-1, dp))%MOD;
    //     result += (solve('e', n-1, dp))%MOD;
    //     result += (solve('i', n-1, dp))%MOD;
    //     result += (solve('o', n-1, dp))%MOD;
    //     result += (solve('u', n-1, dp))%MOD;
    //     return result;
    // }
};