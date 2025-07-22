int jump(int* nums, int numsSize){
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        farthest = fmax(farthest, i + nums[i]);
        if (i == current_end) {
            jumps++;
            current_end = farthest;
        }
    }
    return jumps;
}
