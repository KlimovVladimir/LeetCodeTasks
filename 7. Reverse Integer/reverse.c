int reverse(int x) {
    long int digit = 0, result = 0;

    while (x != 0) {
        digit = x % 10;
        
        if (result > INT_MAX / 10 || result < INT_MIN / 10)
            return 0;

        result = result * 10 + digit;
        x = x / 10;
    }
    
    return result;
}
