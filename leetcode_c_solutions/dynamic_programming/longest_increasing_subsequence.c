int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }

    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int maxLen = 0;

    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = maxLen;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        dp[left] = nums[i];
        if (left == maxLen) {
            maxLen++;
        }
    }

    free(dp);
    return maxLen;
}
