class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>temp;
        for(int i = 0 ; i < n ; i++){
            int subArrSum = 0;
            for(int j = i ; j < n ; j++){
                subArrSum += nums[j];
                temp.push_back(subArrSum);
            }
        }
        sort(temp.begin(), temp.end());
        int ansSum = 0;
        for(int i = left-1 ; i <= right-1 ; i++){ // -1 is done bcoz temp is 0 based indexing and nums is 1 based indexing
            ansSum = (ansSum + temp[i]) % M;
        }
        return ansSum;
    }
};