int minSubArrayLen(int target, int* nums, int numsSize){
    int minLength = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];
        while (sum >= target) {
            minLength = fmin(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}
