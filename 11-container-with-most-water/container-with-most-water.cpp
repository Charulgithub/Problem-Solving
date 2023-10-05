class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0 ;   // maxwater==maxarea
        int left = 0 , right = height.size()-1;

        while( left < right){
            int minHeight = min ( height[left], height[right]);
            int currArea = abs(right - left)*minHeight;
            maxwater = max(maxwater, currArea);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxwater;
    }
};