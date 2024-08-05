class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans = "";
        int n = arr.size();
        unordered_map<string, int> mp;
        for( string str : arr){
            mp[str]++;
        }
        for( string s : arr){
            if(mp[s] == 1) k--;

            if( k == 0) return s;
        }
        return ans;
    }
};