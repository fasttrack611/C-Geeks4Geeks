#include <stdio.h>
#include "two_sum.c"
#include "best_time_to_buy_and_sell_stock.c"
#include "merge_sorted_array.c"
#include "contains_duplicate.c"
#include "product_of_array_except_self.c"
#include "maximum_subarray.c"
#include "3sum.c"
#include "merge_intervals.c"
#include "container_with_most_water.c"
#include "rotate_image.c"

int main() {
    // two_sum
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    printf("two_sum: [%d, %d]\n", result[0], result[1]);

    // maxProfit
    int prices[] = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices, 6);
    printf("maxProfit: %d\n", profit);

    // merge
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3, 3);
    printf("merge: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // containsDuplicate
    int nums3[] = {1, 2, 3, 1};
    bool hasDuplicate = containsDuplicate(nums3, 4);
    printf("containsDuplicate: %s\n", hasDuplicate ? "true" : "false");

    // productExceptSelf
    int nums4[] = {1, 2, 3, 4};
    int returnSize2;
    int* result2 = productExceptSelf(nums4, 4, &returnSize2);
    printf("productExceptSelf: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    // maxSubArray
    int nums5[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = maxSubArray(nums5, 9);
    printf("maxSubArray: %d\n", maxSum);

    return 0;
}
