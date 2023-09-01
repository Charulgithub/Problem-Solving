class Solution {
public:   
    vector<int> countBits(int n) {
         vector<int> result(n+1);
         if(n==0) return result;
         result[0] = 0; //no. of set bits in 0 is 0

         for(int i = 0; i < n+1; i++ ){
             if(i%2 == 0) result[i] = result[i/2];

             else result[i] = result[i/2] + 1;
         }
         return result;
    }

/*   --------TC = O(logn)

    vector<int> countBits(int n) {
        vector<int>res(n+1, 0);
        for(int i=0; i<n+1 ; i++){
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
    */
};