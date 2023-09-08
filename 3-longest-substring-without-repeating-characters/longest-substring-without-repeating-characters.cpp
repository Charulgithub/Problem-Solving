class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map< char, int> mp;
        if(s.size() <= 1) return s.size();
        int i = 0, j = 0;
        int maxlen = 1;
        while(j < s.size()){
             mp[s[j]]++;
            
            if(mp.size() > j-i+1){
                j++;
            }

            if(mp.size() == j-i+1){
                maxlen = max(maxlen, j-i+1);
                j++;
            }
            else if( mp.size() < j-i+1){
                while( mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxlen;
    }
};