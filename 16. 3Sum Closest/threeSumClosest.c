int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    
    qsort(nums, numsSize, sizeof(nums[0]), comp);

    int result = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {

        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                return target;
            }


            if (abs(sum - target) < abs(result - target))
                result = sum;
            
            if (sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return result;
}
