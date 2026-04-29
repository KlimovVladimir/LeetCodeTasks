int removeDuplicates(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[result] != nums[i + 1]) {
            result++;
            nums[result] = nums[i + 1];
        }
    }

    return result + 1;
}
