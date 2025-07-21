int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;
    while (left < right) {
        int water = ((right - left) * ((height[left] < height[right]) ? height[left] : height[right]));
        if (water > maxWater) {
            maxWater = water;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxWater;
}
