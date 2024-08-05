class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string output = "";
        for(int i = 0 ; i < arr.size() ; i++){
            bool dist = true;
            for(int j = 0 ; j < arr.size() ; j++){
                if(i != j && arr[i] == arr[j]) {
                    dist = false;
                }
            }
            if(dist == true){
                if( k > 0) k--;
            }
            if(k == 0) return arr[i];
       }
       return output;
    }
};