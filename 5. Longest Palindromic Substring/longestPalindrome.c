int checkPalidrome(char* start, char* end) {
    while (start < end) {
        if (*start != *end)
            return 0;
        start++;
        end--; 
    }
    return 1;
}

char* longestPalindrome(char* s) {

    int length = strlen(s);
    int maxLength = 1;
    char* start;
    char* end;
    char* final = NULL;
    char* result = (char *)malloc((length + 1) * sizeof(char));
    memset(result, 0, length + 1);
    start = s;
    result[0] = *s;

    for (int i = 0; i < length; i++) {
        end = start + 1;
        for (int j = i + 1; j < length; j++) {
            if (checkPalidrome(start, end) == 1)
            {
                if (maxLength < (int)(end - start + 1)) {
                    maxLength = (int)(end - start + 1);
                    final = start;
                }
            }
            end++;
        }
        start++;
    }

    if (final != NULL)
    strncpy(result, final, maxLength);

    return result;
}
