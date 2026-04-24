int searchInsert(int* nums, int numsSize, int target) {
    if (target > nums[numsSize - 1])
        return numsSize;
    else if (target < nums[0])
        return 0;
    
    int start = 0;
    int end = numsSize - 1;
    while (start < end) {
        if (target == nums[start])
            return start;
        else if (target == nums[end])
            return end;
        
        if (target > nums[start])
            start++;
        
        if (target < nums[end])
            end--;
    }

    if (target > nums[start])
        return start + 1;
    else
        return start;
}
