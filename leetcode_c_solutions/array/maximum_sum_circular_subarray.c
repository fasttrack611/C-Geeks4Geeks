int maxSubarraySumCircular(int* nums, int numsSize){
    int totalSum = 0;
    int maxSum = INT_MIN;
    int currentMax = 0;
    int minSum = INT_MAX;
    int currentMin = 0;

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        currentMax += nums[i];
        if (currentMax > maxSum) {
            maxSum = currentMax;
        }
        if (currentMax < 0) {
            currentMax = 0;
        }

        currentMin += nums[i];
        if (currentMin < minSum) {
            minSum = currentMin;
        }
        if (currentMin > 0) {
            currentMin = 0;
        }
    }

    if (maxSum > 0) {
        return fmax(maxSum, totalSum - minSum);
    } else {
        return maxSum;
    }
}
