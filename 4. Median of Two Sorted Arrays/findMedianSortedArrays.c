double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = 0, n = 0;
    int length = 0;

    double arr[nums1Size + nums2Size];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < nums1Size + nums2Size; i++) {
        if ((m < nums1Size) && (n < nums2Size)) {
            if (nums1[m] == nums2[n]) {
                arr[length++] = nums1[m++];
                arr[length++] = nums2[n++];
            }
            else if (nums1[m] < nums2[n]) {
                arr[length++] = nums1[m++];
            }
            else if (nums1[m] > nums2[n]) {
                arr[length++] = nums2[n++];
            }
        }
        else if (m < nums1Size) {
            arr[length++] = nums1[m++];
        }
        else if (n < nums2Size) {
            arr[length++] = nums2[n++];
        }
    }

    if ((length % 2) == 0) {
        int index = length / 2;
        if (index > 0)
            return ((arr[index] + arr[index - 1]) / 2.0);
        else
            return ((arr[index] + arr[index + 1]) / 2.0);
    }
    else {
        int index = length / 2;
        return arr[index];
    }
}