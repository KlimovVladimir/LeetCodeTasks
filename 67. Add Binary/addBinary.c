char* addBinary(char* a, char* b) {
    if (a[0] == '0')
        return b;
    else if (b[0] == '0')
        return a;
    
    int aLength = strlen(a);
    int bLength = strlen(b);
    int resultLenght = aLength > bLength ? aLength + 1 : bLength + 1;
    int resultIndex = resultLenght - 1;
    int transfer = 0;
    
    aLength--;
    bLength--;

    char* result = (char*) malloc(resultLenght * sizeof(char));
    result[resultIndex--] = '\0';

    while (aLength >= 0 || bLength >= 0) {

        if (aLength >= 0) {
            transfer += a[aLength--] - '0';
        }

        if (bLength >= 0) {
            transfer += b[bLength--] - '0';
        }

        result[resultIndex--] = transfer % 2 + '0';
        transfer /= 2;
    }

    if (transfer) {
        result = (char*) realloc(result, (resultLenght + 1) * sizeof(char));
        memmove(result + 1, result, resultLenght);
        result[0] = '1';
    }

    return result;
}
