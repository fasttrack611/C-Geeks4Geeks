int rob(int* nums, int numsSize){
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 0; i < numsSize; i++) {
        int temp = prev1;
        prev1 = fmax(prev2 + nums[i], prev1);
        prev2 = temp;
    }

    return prev1;
}
