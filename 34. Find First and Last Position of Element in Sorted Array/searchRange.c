/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*) malloc(*returnSize * sizeof(int));
    int left = 0, right = numsSize - 1;
    memset(result, -1, sizeof(result));

    while (left <= right) {
        if (nums[left] == target) {
            result[0] = left;

            while (left < numsSize && nums[left] == target) {
                left++;
            }
            result[1] = left - 1;
            break;
        }
        else {
            left++;
        }

        if (nums[right] == target) {
            result[1] = right;

            while (right > 0 && nums[right] == target) {
                right--;
            }
            result[0] = right + 1;
            break;
        }
        else {
            right--;
        }
    }

    return result;

}
