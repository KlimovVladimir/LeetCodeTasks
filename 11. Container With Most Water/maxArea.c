int maxArea(int* height, int heightSize) {
    int max = 0;
    int start = 0;
    int end = heightSize - 1;

    // for (int i = 0; i < heightSize - 1; i++) {
    //     for (int j = i + 1; j < heightSize; j++) {
    //         int min = height[i] < height[j] ? height[i] : height[j];
    //         int square = min * (j - i);
    //         if (square > max)
    //             max = square;
    //     }
    // }

    for (int i = 0; i < heightSize; i++) {
        int min = height[start] < height[end] ? height[start] : height[end];
        int square = min * (end - start);
        if (square > max)
            max = square;
        
        if (height[start] < height[end])
            start++;
        else
            end--;
    }
    
    return max;
}
