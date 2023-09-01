class Solution {
public:
string reverseWords(string s) {
     
      if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }

    /* ---brute force
    
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
// to push last word
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
*/

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