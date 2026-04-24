int furthestDistanceFromOrigin(char* moves) {
    int L = 0, R = 0;
    for (int i = 0; i < strlen(moves); i++) {
        if (moves[i] == 'L') {
            L++;
            R--;
        }
        else if (moves[i] == 'R') {
            R++;
            L--;
        }
        else {
            L++;
            R++;
        }
    }

    if (L > R)
        return L;
    else
        return R;
}
