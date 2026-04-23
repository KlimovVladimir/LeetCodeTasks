/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursion(char** result, int* returnSize, char* current, int index, int open, int close, int n) {
    if (index == (n * 2)) {
        current[index] = '\0';
        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    
    if (open < n) {
        current[index] = '(';
        recursion(result, returnSize, current, index + 1, open + 1, close, n);
    }
    
    if (close < open) {
        current[index] = ')';
        recursion(result, returnSize, current, index + 1, open, close + 1, n);
    }
}


char** generateParenthesis(int n, int* returnSize) {
    char** result = (char **)malloc(10000 * sizeof(char *));
    char* current = (char*)malloc(((n * 2) + 1) * sizeof(char));
    *returnSize = 0;
    recursion(result, returnSize, current, 0, 0, 0, n);

    free(current);
    return result;
}
