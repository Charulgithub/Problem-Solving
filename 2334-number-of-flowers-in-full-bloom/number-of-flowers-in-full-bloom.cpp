class Solution {
public:
      
   vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    int n = people.size();
    int m = flowers.size();
    vector<int> result(n);
    vector<int> bloom(m);
    vector<int> died(m);

    for (int i = 0; i < m; i++) {
        bloom[i] = flowers[i][0];
        died[i] = flowers[i][1];
    }
    sort(bloom.begin(), bloom.end());
    sort(died.begin(), died.end());

    for (int i = 0; i < n; i++) {
        int time = people[i];
        int x = upper_bound(bloom.begin(), bloom.end(), time) - bloom.begin(); // bloomed flowers already
        int y = lower_bound(died.begin(), died.end(), time) - died.begin(); // died flowers already
        result[i] = x - y;
    }
    return result;
}


/* BRUTE-->TLE 

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int>result; // vector<int>result(n); 

        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            for(int j = 0 ; j < m ; j++){
                int start = flowers[j][0];
                int end = flowers[j][1];
                if(people[i] >= start && people[i] <= end) cnt++; // result[i]++;
            }
            result.push_back(cnt);
        }
        return result;
    }
    */
};