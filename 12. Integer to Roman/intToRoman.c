char* intToRoman(int num) {
    int power = (int)log10(num);
    char* oneList = "MCXI";
    char* fiveList = "_DLV";

    oneList = oneList + (3 - power);
    fiveList = fiveList + (3 - power);

    char* result = (char*)malloc(sizeof(char) * 16);
    memset(result, 0, 16);

    char* curr = result;

    while (num > 0) {

        int digit = num / (int)pow(10, power);

        if (digit == 5) {
            *curr = *fiveList;
            curr++;
        }
        else if (digit == 4) {
            *curr = *oneList;
            curr++;
            *curr = *fiveList;
            curr++;
        }
        else if (digit == 9) {
            *curr = *oneList;
            curr++;
            *curr = *(oneList - 1);
            curr++;
        }
        else if (digit <= 3) {
            for (int i = 0; i < digit; i++) {
                *curr = *oneList;
                curr++;
            }
        }
        else if (digit >= 6) {
            *curr = *fiveList;
            curr++;
            for (int i = 0; i < (digit - 5); i++) {
                *curr = *oneList;
                curr++;
            }
        }

        num -= digit * (int)pow(10, power);
        power--;
        oneList++;
        fiveList++;
    }


    return result;
}
