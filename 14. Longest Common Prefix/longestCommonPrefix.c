char* longestCommonPrefix(char** strs, int strsSize) {
    int minLength = strlen(strs[0]);
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) < minLength)
            minLength = strlen(strs[i]);
    }

    char* result = (char *) malloc(sizeof(char) * (minLength + 1));
    memset(result, 0, minLength + 1);

    char* current = result;
    while (minLength > 0) {
        char letter = *strs[0];
        for (int i = 0; i < strsSize; i++) {
            if (letter != *strs[i]) {
                return result;
            }
            strs[i]++;
        }
        *current = letter;
        current++;
        minLength--;
    }

    return result;
}
