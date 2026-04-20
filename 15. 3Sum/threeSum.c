int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    qsort(nums, numsSize, sizeof(nums[0]), comp);

    long long maxTriplets = 1;
    int** result = malloc((long long)maxTriplets * sizeof(int*));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                if (*returnSize >= maxTriplets) {
                    maxTriplets *= 2;
                    result = realloc(result, maxTriplets * sizeof(int*));
                }

                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                j++;
                k--;
                (*returnSize)++;

                while (j < k && nums[j] == nums[j-1]) j++;
                while (j < k && nums[k] == nums[k+1]) k--;
            }
            else if (sum < 0) {
                j++;
            }
            else 
                k--;
        }
    }

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
