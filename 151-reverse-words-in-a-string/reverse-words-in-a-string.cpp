class Solution {
public:
string reverseWords(string s) {
    int n = s.size();
    vector<string> v;
    string temp = "";

    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            temp += s[i];
        } else if (!temp.empty()) {
            v.push_back(temp);
            temp = "";
        }
    }

    if (!temp.empty()) {
        v.push_back(temp);
    }

    reverse(v.begin(), v.end());

    string ans = "";
    for (int i = 0; i < v.size(); i++) {
        ans += v[i];
        if (i < v.size() - 1) {
            ans += " ";
        }
    }

    return ans;
}

    // string reverseWords(string s) {
    //     int n = s.size();
    //     vector<string> v(n);
    //     string temp = "";
    //     for(int i =0; i<s.size(); i++){
    //         if(s[i] != ' '){
    //             temp += s[i];
    //         }
    //         v.push_back(temp);
    //             temp = "";
    //     }
    //     reverse(v.begin(), v.end());
    //     string ans = "";
    //     for(int i=0; i<n; i++) ans+=v[i];
    //     return ans;
   // }
};