#include <stdio.h>

int main() {

    int matrix[2][2];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }

    printf("\n%d\n", matrix[0][4]);

    int* matrixPtr = &matrix[0][0];

    return 0;
}