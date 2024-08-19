class Solution {
public:
    int solve ( int currA, int clipA, int n){
        if(currA == n){
            return 0;
        }
        
        if(currA > n){ // invalid hojayega
            return 10000;
        }

        //2 options now
        int paste = 1 + solve(currA + clipA, clipA, n);

        int copyAllpaste = 1 + 1 + solve(currA + currA, currA, n);

        return min(paste, copyAllpaste);
    }
    int minSteps(int n) {
        if ( n == 1){
            return 0;//since 1 A is present in notepad
        }
        // +1 pehle se isliye kiya hai kyuki , pehle copy karna hi padega bfore performing any operation
        return 1 + solve(1, 1, n);
    }
};