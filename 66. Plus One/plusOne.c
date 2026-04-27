/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int resultSize = digitsSize + 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            resultSize = digitsSize;
            break;
        }
    }
    int* result = (int*) malloc ((resultSize) * sizeof(int));
    int plusOne = 1;
    *returnSize = 0;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (plusOne) {
            if (digits[i] + 1 == 10)
                result[resultSize - 1] = 0;
            else {
                result[resultSize - 1] = digits[i] + 1;
                plusOne = 0;
            }
        }
        else
            result[resultSize - 1] = digits[i];
        
        resultSize--;
        (*returnSize)++;
    }

    if (plusOne) {
        result[0] = 1;
        (*returnSize)++;
    }

    return result;
}
