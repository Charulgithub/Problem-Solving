class Solution {
public:
    int minDeletions(string s) {
        //Approach -1.......tc 
        vector<int>freq(26, 0);
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
    }
};