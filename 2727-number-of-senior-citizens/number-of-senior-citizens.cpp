class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count = 0;
        for( int i = 0 ; i < n ; i++){
           string passen = details[i];
           string age = "";
           age += passen[11];
           age += passen[12];

           int ageNum = stoi (age);
           if( ageNum > 60) count++;
        }
        return count;
    }
};