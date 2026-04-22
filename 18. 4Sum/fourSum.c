int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    
    qsort(nums, numsSize, sizeof(nums[0]), comp);

    long long maxQuadruplets = 1;
    int** result = malloc((long long)maxQuadruplets * sizeof(int*));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;

            int n = j + 1;
            int k = numsSize - 1;
            while (n < k) {
                long sum = (long)nums[i] + (long)nums[j] + (long)nums[n] + (long)nums[k];
                if (sum == target) {
                    if (*returnSize >= maxQuadruplets) {
                        maxQuadruplets *= 2;
                        result = realloc(result, maxQuadruplets * sizeof(int*));
                    }

                    result[*returnSize] = malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[n];
                    result[*returnSize][3] = nums[k];
                    (*returnSize)++;
                    n++;
                    k--;

                    while (n < k && nums[n] == nums[n-1]) n++;
                    while (n < k && nums[k] == nums[k+1]) k--;
                }
                else if (sum < target) {
                    n++;
                }
                else 
                    k--;
            }
        }
    }

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }

    return result;
}
