int comp(const void *a, const void *b) {
    if (*(int *)a == INT_MIN || *(int *)b == INT_MIN)
        return INT_MIN;
    return (*(int *)a - *(int *)b);
}

int firstMissingPositive(int* nums, int numsSize) {
    int result = 1;

    qsort(nums, numsSize, sizeof(nums[0]), comp);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > result)
            return result;
        else if (nums[i] == result) {
            result = nums[i] + 1;
        }
    }

    return result;
}
