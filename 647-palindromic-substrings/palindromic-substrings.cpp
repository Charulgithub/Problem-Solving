class Solution {
public:
    int checkPal ( int i , int j , string& s){
        if( i >= j) return 1;
        if( s[i] == s[j] && checkPal(i+1, j-1, s)) return 1;
        else return 0;
    }
    int countSubstrings(string s) {
        int cnt = 0 ; 
        for( int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                cnt += checkPal ( i, j, s);
            }
        }
        return cnt;
    }
};