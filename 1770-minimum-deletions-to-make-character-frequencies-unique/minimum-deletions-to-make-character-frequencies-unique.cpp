class Solution {
public:
    int minDeletions(string s) {
       //Approach-2 not be using set
       vector<int>freq(26, 0);
       for(char &ch : s) freq[ch-'a']++;

       int numDel = 0;
       sort(freq.begin(), freq.end());
       for(int i = 24; i >= 0 && freq[i]>0 ; i--){
           if(freq[i] >= freq[i+1]){
               int prev = freq[i];
               freq[i] = max(0, freq[i+1]-1);
               numDel += prev - freq[i];
           }
       }
 return numDel;

        //Approach -1.......tc-->O(26)+O(N)--set, sc = O(N)

      /*  vector<int>freq(26, 0);
        for(char &ch : s){
            freq[ch-'a']++;
        }
        int numDel = 0;
        unordered_set<int> st;

        for(int i = 0 ; i < 26 ; i++){
            while(freq[i] > 0 && st.find(freq[i]) != st.end()){
                freq[i]--;
                numDel++;
            }
            st.insert(freq[i]);
        }
        return numDel;
        */
    }
};