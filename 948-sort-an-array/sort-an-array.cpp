class Solution {
public:
    vector<int> sortArray(vector<int>& nums) { //we'll do this by counting sort
       
       unordered_map<int, int>freq;
       for(auto &num : nums){
        freq[num]++;
       }
       int minE = *min_element(nums.begin(), nums.end());
       int maxE = *max_element(nums.begin(), nums.end());

       int ind = 0;
       for(int i = minE ; i <= maxE ; i++){
         while(freq[i] > 0){
            nums[ind] = i;//i here refers to num, not index
            freq[i]--;
            ind++;
         }
       } 
       return nums;
    }
};