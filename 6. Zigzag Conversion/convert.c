char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) == 1)
        return s;
    
    int isDown = 1;
    int currCol = 0, currRow = 0;

    int length = strlen(s);
    char **matrix = (char **)malloc(numRows * sizeof(char *));
  
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (char *)malloc(((length / 2) + 1) * sizeof(char));
        memset(matrix[i], 0, (length / 2) + 1);
    }

    while (*s != '\0') {
        if (isDown == 1) {
            if (currRow == numRows) {
                isDown = 0;
                currCol++;
                currRow = currRow - 2;
            }
            else {
                matrix[currRow][currCol] = *s;
                s++;
                currRow++;
            }
        }
        else {
            if (currRow == 0) {
                isDown = 1;
                if (numRows > 2)
                    currCol++;
            }
            else {
                matrix[currRow][currCol] = *s;
                s++;
                currRow--;
            }
        }
    }

    int k = 0;
    char* result = (char *)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < (length / 2) + 1; j++) {
            if (matrix[i][j] != '\0')
                result[k++] = matrix[i][j];
        }
    }
    result[k] = '\0';

    return result;
}
