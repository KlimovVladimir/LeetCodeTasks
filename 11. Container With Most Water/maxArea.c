int maxArea(int* height, int heightSize) {
    int max = 0;
    int start = 0;
    int end = heightSize - 1;

    while (start < end) {
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
