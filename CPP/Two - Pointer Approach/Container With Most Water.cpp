int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxVol = 0;
        while (left < right) {
            // Calculate the height of the shorter line
            int minHeight = min(height[left], height[right]);
            // Calculate the width (distance between the lines)
            int width = right - left;
            // Calculate the current volume and update maxVolume if necessary
            maxVol = max(maxVol, minHeight * width);
            // Move the pointer at the shorter line inward
            if (height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxVol;
}
