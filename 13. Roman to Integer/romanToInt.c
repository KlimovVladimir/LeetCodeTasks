int romanToInt(char* s) {
    int length = strlen(s);
    int result = 0;

    for (int i = 0; i < length; i++) {
        switch (*s) {
            case 'I':
                if (*(s + 1) == 'V') {
                    result += 4;
                    s++;
                    i++;
                    break;
                }
                else if (*(s + 1) == 'X') {
                    result += 9;
                    s++;
                    i++;
                    break;
                }
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (*(s + 1) == 'L') {
                    result += 40;
                    s++;
                    i++;
                    break;
                }
                else if (*(s + 1) == 'C') {
                    result += 90;
                    s++;
                    i++;
                    break;
                }
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (*(s + 1) == 'D') {
                    result += 400;
                    s++;
                    i++;
                    break;
                }
                else if (*(s + 1) == 'M') {
                    result += 900;
                    s++;
                    i++;
                    break;
                }
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
        }
        s++;
    }
    return result;
}
