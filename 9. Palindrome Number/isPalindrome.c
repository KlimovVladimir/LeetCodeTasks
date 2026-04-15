bool isPalindrome(int x) {
    if (x < 0)
        return false;

    if ((x / 10) == 0)
        return true;

    char begin;
    char end;
    int xcopy = x, length = 0;

    while (xcopy > 0) {
        length++;
        xcopy = xcopy / 10;
    }

    while (x > 0) {
        begin = (x % 10) + '0';
        end = ((int)(x / pow(10, length - 1))) + '0';
        if (begin != end)
            return false;
        x = x % (int)pow(10, length - 1);
        x = x / 10;
        length = length - 2;
    }

    return true;
}
