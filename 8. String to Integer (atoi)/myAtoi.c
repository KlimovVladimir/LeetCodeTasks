int myAtoi(char* s) {
    int length = strlen(s);
    int isNegative = 0, numberStart = -1, bitWidth = -1;
    long int result = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == ' ' && numberStart == -1)
            continue;
        else if ((s[i] == '-' || s[i] == '+') && numberStart == -1) {
            if (i < length) {
                if ((s[i + 1] >= 48 && s[i + 1] <= 57)) {
                    isNegative = (s[i] == '-') ? 1 : 0;
                    continue;
                }
                else
                    break;
            }
        }
        else if (s[i] < 48 || s[i] > 57)
            break;

        if (numberStart == -1) {
            numberStart = i;
        }
        bitWidth++;
    }

    if (numberStart == -1)
        return 0;

    length = numberStart + bitWidth + 1;
    for (int i = numberStart; i < length; i++) {
        if (result + (int)(s[i] - '0') * pow(10, bitWidth) > INT_MAX && !isNegative)
            return INT_MAX;
        else if (result + (int)(s[i] - '0') * pow(10, bitWidth) > INT_MAX &&isNegative)
            return INT_MIN;

        result += (int)(s[i] - '0') * pow(10, bitWidth);
        //or
        //result += (int)(s[i] & 0x457) * pow(10, bitWidth);
        bitWidth--;
    }

    if (isNegative) {
        result = ~result + 1;
    }

    return result;
}