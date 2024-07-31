class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>rightA(n,0);

        int counta = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            rightA[i] = counta;
            if(s[i] == 'a') counta++;
        }

        int count = INT_MAX;
        int countb = 0;
        for(int i = 0 ; i < n ; i++){
            count = min(count, countb + rightA[i]);

            if(s[i] == 'b') countb++;
        }
        return count;
    }
};