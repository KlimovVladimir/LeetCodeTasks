/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char* mapping[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void recursion(char* digits, int* returnSize, char** result, char* current, int index, int depth) {
    if (depth == index) {
        current[depth] = '\0';
        result[*returnSize] = (char*)malloc((depth + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    int digit = digits[depth] - '0';
    const char* letters = mapping[digit];
    
    for (int i = 0; letters[i] != '\0'; i++) {
        current[depth] = letters[i];
        recursion(digits, returnSize, result, current, index, depth + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int length = strlen(digits);
    int combiCount = 1;
    *returnSize = 0;
   
    for (int i = 0; i < length; i++) {
        combiCount *= strlen(mapping[digits[i] - '0']);
    }

    char** result = (char**)malloc(combiCount * sizeof(char*));
    char* current = (char*)malloc((length + 1) * sizeof(char));

    recursion(digits, returnSize, result, current, length, 0);
    
    free(current);
    return result;
}
