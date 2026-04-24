int strStr(char* haystack, char* needle) {
    int length = strlen(haystack);

    if (length < strlen(needle))
        return -1;

    char* needleP = needle;
    int result = -1;
    for (int i = 0; i < length; i++) {
        if (*needleP == '\0')
            return result;
        
        if (haystack[i] == *needleP) {
            if (result == -1)
                result = i;
            needleP++;
        }
        else {
            if (result != -1)
                i = result;
            needleP = needle;
            result = -1;
        }
    }

    if (*needleP != '\0')
        return -1;

    return result;
}
